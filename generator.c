//
// Created by MagicBook on 2020/12/26.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"
#include "table.h"
#include "generator.h"

int indirectTripleCodeGenerator(GrammarTree node, struct Instruction* instruction) {
    if (NULL == node) {
        return -65536;
    }
    if (NULL == instruction) {
        return -65535;
    }
    char go[64];

    int trueList;
    int falseList;

    int leftTrue;
    int rightTrue;
    int leftFalse;
    int rightFalse;
    int jump;
    int assign;

    GrammarTree parent;

    int cursor = 0;
    switch (node->opt) {
        case _ERROR:
            printf("Error for %s.\n", node->word);
            exit(-1);
        case _VOID:
            node->type = 0;
            break;
        case _INT:
            node->type = 1;
            break;
        case _FOR:
            node->begin = makeNewTemp(instruction, generateIndirectTriple("j", "_", "_"));
            node->end = makeNewTemp(instruction, generateIndirectTriple("j", "_", "_"));
            indirectTripleCodeGenerator(node->child[0], instruction);
//            if (-1 != node->child[0]->begin) {
//                sprintf(go, "%d", node->child[0]->begin);
//                rewriteTemp(instruction, node->begin, 2, go);
//                if (-1 != node->child[0]->head) {
//                    node->head = node->child[0]->head;
//                }
//            }
            // These value must include in action at least.
            sprintf(go, "%d", node->child[0]->begin);
            rewriteTemp(instruction, node->begin, 2, go);
            node->head = node->child[0]->head;

            indirectTripleCodeGenerator(node->child[1], instruction);
            // 回填stmt头
            // stmt 回填尾部
            // action回填head
            // End.
            jump = makeNewTemp(instruction, generateIndirectTriple("!", node->value, "_"));
            sprintf(go, "%d", jump);
            rewriteTemp(instruction, node->end, 2, go);

//            node->begin = makeNewTemp(instruction, generateIndirectTriple("j", "_", "_"));
//            node->end = makeNewTemp(instruction, generateIndirectTriple("j", "_", "_"));
//
//            indirectTripleCodeGenerator(node->child[1], instruction);
//            if (-1 != node->child[1]->begin) {
//                sprintf(go, "%d", node->child[1]->begin);
//                rewriteTemp(instruction, node->begin, 2, go);
//            }
//            indirectTripleCodeGenerator(node->child[0], instruction);
//            if (-1 == node->begin) {
//                node->begin = node->child[0]->begin;
//            }
//            trueList = makeNewTemp(instruction, generateIndirectTriple("j",
//                                                                       node->child[0]->value, "_"));
//            sprintf(go, "%d", node->end);
//            falseList = makeNewTemp(instruction, generateIndirectTriple("j", "_",
//                                                                        go));
//            if (-1 != node->child[0]->begin) {
//                node->head = node->child[0]->begin;
//            }
//            else {
//                node->head = trueList;
//            }
            break;
        case _FOR_INIT:
            indirectTripleCodeGenerator(node->child[0], instruction);
            break;
        case _FOR_CONDITION:
            break;
        case _FOR_ACTION:
            break;
        case _FOR_EXPRESSION:

            break;
        case _WHILE_CONDITION:
            break;
        case _DO_WHILE:
            break;
        case _DO:
            break;
        case _WHILE:
            break;
        case _CONTINUE:
            parent = node->parent;
            while (NULL != parent) {
                if (_FOR != parent->opt) {

                }
                else if (_DO_WHILE != node->opt) {

                } else if (_WHILE != node->opt) {

                }
                else {
                    break;
                }
                parent = parent->parent;
            }
            sprintf(go, "%d", parent->head);
            node->begin = makeNewTemp(instruction, generateIndirectTriple("j", "_",
                                                                          go));
            node->end = node->begin;
            break;
        case _BREAK:
            parent = node->parent;
            while (NULL != parent) {
                if (_FOR != parent->opt) {

                }
                else if (_DO_WHILE != node->opt) {

                } else if (_WHILE != node->opt) {

                }
                else {
                    break;
                }
                parent = parent->parent;
            }
            sprintf(go, "%d", parent->end);
            node->begin = makeNewTemp(instruction, generateIndirectTriple("j", "_",
                                                                          go));
            node->end = node->begin;
            break;
        case _IF:
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            trueList = makeNewTemp(instruction, generateIndirectTriple("j", node->child[0]->value, "_"));
            falseList = makeNewTemp(instruction, generateIndirectTriple("j", "_", "_"));
            indirectTripleCodeGenerator(node->child[1], instruction);
            sprintf(go, "%d", node->child[1]->begin);
            rewriteTemp(instruction, trueList, 2, go);

            if (3 == node->size) {
                // ELSE;
                indirectTripleCodeGenerator(node->child[2], instruction);
                sprintf(go, "%d", node->child[2]->begin);
                rewriteTemp(instruction, falseList, 2, go);
            }
            node->end = makeNewTemp(instruction, generateIndirectTriple("!", node->value, "_"));
            if (2 == node->size) {
                sprintf(go, "%d", node->end);
                rewriteTemp(instruction, falseList, 2, go);
            }
            break;
        case _ELSE:
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            node->end = node->child[0]->end;
            break;
        case _IF_STMT:
            pushScope(0);
            if (node->size && -1 != node->child[0]->begin) {
                indirectTripleCodeGenerator(node->child[0], instruction);
                node->begin = node->child[0]->begin;
                node->end = node->child[0]->end;
            }
            else {
                node->begin = makeNewTemp(instruction, generateIndirectTriple("!", "1", "_"));
                node->end = node->begin;
            }
            popScope();
            break;
        case _IF_CONDITION:
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            sprintf(node->value, "%s", node->child[0]->value);
            node->end = node->child[0]->end;
            break;
        case _RETURN:
            node->begin = makeNewTemp(instruction, generateIndirectTriple("j", "_", "-1"));
            node->end = node->begin;
            break;
        case _ADDRESS: // ==============================================================================================
            // &
            break;
        case _ARRAY: // ================================================================================================
            // Array.
            break;
        case _LPRP:
            // ()
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            node->end = node->child[0]->end;
            if (-1 == node->child[0]->begin) {
                node->begin = makeNewTemp(instruction, generateIndirectTriple("n", "_", "4"));
                sprintf(go, "@%d", node->begin);
                rewriteTemp(instruction, node->begin, 1, go);
                node->end = node->begin;
            }
            sprintf(node->value, "%s", node->child[0]->value);
            break;
        case _SLPRP: // ================================================================================================
            // []
            break;
        case _LOOP:
            node->head = 0;
            pushScope(0);

            popScope();
            break;
        case _POINTER: // ==============================================================================================
            break;
        case _ASSIGN:
            node->type = 12;
            if (_ID != node->child[0]->opt) {
                printf("Wrong assign for not id at left.\n");
                exit(-2);
            }
            indirectTripleCodeGenerator(node->child[1], instruction);
            if (0 > getWordInfo(node->child[1]->word)->store) {
                printf("Using not inited value.\n");
                exit(-3);
            }
            node->begin = node->child[1]->begin;
            indirectTripleCodeGenerator(node->child[0], instruction);
            if (-1 == node->begin) {
                node->begin = node->child[0]->begin;
            }
            node->end = makeNewTemp(instruction, generateIndirectTriple("=",
                                                                        node->child[0]->value,
                                                                        node->child[1]->value));
            if (-1 == node->begin) {
                node->begin = node->end;
            }
            break;
        case _DECLARATION: // ==========================================================================================
            break;
        case _ARGUMENT_DECLARATION_LIST: // ============================================================================
            break;
        case _DECLARATION_BODY: // =====================================================================================
            break;
        case _ARGUMENT_DECLARATION_UNIT: // ============================================================================
            break;
        case _EQUAL:
            node->type = 12;
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            indirectTripleCodeGenerator(node->child[1], instruction);
            if (-1 == node->begin) {
                node->begin = node->child[1]->begin;
            }
            node->end = makeNewTemp(instruction, generateIndirectTriple("==",
                                                                        node->child[0]->value,
                                                                        node->child[1]->value));
            if (-1 == node->begin) {
                node->begin = node->end;
            }
            break;
        case _NOTEQUAL:
            node->type = 12;
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            indirectTripleCodeGenerator(node->child[1], instruction);
            if (-1 == node->begin) {
                node->begin = node->child[1]->begin;
            }
            node->end = makeNewTemp(instruction, generateIndirectTriple("!=",
                                                                        node->child[0]->value,
                                                                        node->child[1]->value));
            if (-1 == node->begin) {
                node->begin = node->end;
            }
            break;
        case _GT:
            node->type = 12;
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            indirectTripleCodeGenerator(node->child[1], instruction);
            if (-1 == node->begin) {
                node->begin = node->child[1]->begin;
            }
            node->end = makeNewTemp(instruction, generateIndirectTriple(">",
                                                            node->child[0]->value,
                                                            node->child[1]->value));
            if (-1 == node->begin) {
                node->begin = node->end;
            }
            sprintf(node->value, "#%d", node->end);
            break;
        case _LT:
            node->type = 12;
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            indirectTripleCodeGenerator(node->child[1], instruction);
            if (-1 == node->begin) {
                node->begin = node->child[1]->begin;
            }
            node->end = makeNewTemp(instruction, generateIndirectTriple("<",
                                                            node->child[0]->value,
                                                            node->child[1]->value));
            if (-1 == node->begin) {
                node->begin = node->end;
            }
            sprintf(node->value, "#%d", node->end);
            break;
        case _GE:
            node->type = 12;
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            indirectTripleCodeGenerator(node->child[1], instruction);
            if (-1 == node->begin) {
                node->begin = node->child[1]->begin;
            }
            node->end = makeNewTemp(instruction, generateIndirectTriple(">=",
                                                            node->child[0]->value,
                                                            node->child[1]->value));
            if (-1 == node->begin) {
                node->begin = node->end;
            }
            sprintf(node->value, "#%d", node->end);
            break;
        case _LE:
            node->type = 12;
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            if (-1 == node->begin) {
                node->begin = node->child[1]->begin;
            }
            indirectTripleCodeGenerator(node->child[1], instruction);
            node->end = makeNewTemp(instruction, generateIndirectTriple("<=",
                                                            node->child[0]->value,
                                                            node->child[1]->value));
            if (-1 == node->begin) {
                node->begin = node->end;
            }
            sprintf(node->value, "#%d", node->end);
            break;
        case _AND:
            node->type = 12;
            node->begin = makeNewTemp(instruction, generateIndirectTriple("n", "_", "4"));
            sprintf(go, "@%d", node->begin);
            rewriteTemp(instruction, node->begin, 1, go);
            sprintf(node->value, "#%d", node->begin);

            indirectTripleCodeGenerator(node->child[0], instruction);
            leftTrue = makeNewTemp(instruction, generateIndirectTriple("j",
                                                                        node->child[0]->value, "_"));
            leftFalse = makeNewTemp(instruction, generateIndirectTriple("j","_", "_"));
            indirectTripleCodeGenerator(node->child[1], instruction);
            sprintf(go, "%d", node->child[1]->begin);
            rewriteTemp(instruction, leftTrue, 2, go);
            rightTrue = makeNewTemp(instruction, generateIndirectTriple("j", node->child[1]->value, "_"));
            rightFalse = makeNewTemp(instruction, generateIndirectTriple("j", "_", "_"));
            node->trueList = makeNewTemp(instruction, generateIndirectTriple("=",
                                                                             node->value, "1"));
            sprintf(go, "%d", node->trueList);
            rewriteTemp(instruction, rightTrue, 2, go);
            jump = makeNewTemp(instruction, generateIndirectTriple("j", "_", "_"));
            node->falseList = makeNewTemp(instruction, generateIndirectTriple("=",
                                                                              node->value, "0"));
            sprintf(go, "%d", node->falseList);
            rewriteTemp(instruction, leftFalse, 2, go);
            rewriteTemp(instruction, rightFalse, 2, go);
            node->end = makeNewTemp(instruction, generateIndirectTriple("=",
                                                                        node->value, node->value));
            sprintf(go, "%d", node->end);
            rewriteTemp(instruction, jump, 2, go);
//            node->type = 12;
//            node->begin = makeNewTemp(instruction, generateIndirectTriple("j", "_", "_"));
//            node->end = makeNewTemp(instruction, generateIndirectTriple("j", "_", "_"));
//
//            indirectTripleCodeGenerator(node->child[0], instruction);
//            node->begin = makeNewTemp(instruction, generateIndirectTriple("j",
//                                                                          node->child[0]->value, "_"));
//            makeNewTemp(instruction, generateIndirectTriple("j", "_", "_"));
//            indirectTripleCodeGenerator(node->child[1], instruction);
//            sprintf(go, "%d", node->child[1]->begin);
//            rewriteTemp(instruction, node->begin, 2, go);
//
//            rewriteTemp(instruction, node->child[0]->end, 2, "end");
//            rewriteTemp(instruction, node->child[1]->end, 2, "end");
            break;
        case _OR:
            node->type = 12;
            node->begin = makeNewTemp(instruction, generateIndirectTriple("n", "_", "4"));
            sprintf(go, "@%d", node->begin);
            rewriteTemp(instruction, node->begin, 1, go);
            sprintf(node->value, "#%d", node->begin);
            indirectTripleCodeGenerator(node->child[0], instruction);
            leftTrue = makeNewTemp(instruction, generateIndirectTriple("j",
                                                                        node->child[0]->value, "_"));
            indirectTripleCodeGenerator(node->child[1], instruction);
            leftFalse = makeNewTemp(instruction, generateIndirectTriple("j",
                                                                        node->child[1]->value, "_"));
            rightFalse = makeNewTemp(instruction, generateIndirectTriple("j", "_", "_"));
            node->trueList = makeNewTemp(instruction, generateIndirectTriple("=",
                                                                             node->value, "1"));
            sprintf(go, "%d", node->trueList);
            rewriteTemp(instruction, leftTrue, 2, go);
            rewriteTemp(instruction, leftFalse, 2, go);
            jump = makeNewTemp(instruction, generateIndirectTriple("j", "_", "_"));
            node->falseList = makeNewTemp(instruction, generateIndirectTriple("=",
                                                                              node->value, "0"));
            sprintf(go, "%d", node->falseList);
            rewriteTemp(instruction, rightFalse, 2, go);
            node->end = makeNewTemp(instruction, generateIndirectTriple("=",
                                                                        node->value, node->value));
            sprintf(go, "%d", node->end);
            rewriteTemp(instruction, jump, 2, go);
//            node->type = 12;
//            indirectTripleCodeGenerator(node->child[0], instruction);
//            node->begin = makeNewTemp(instruction, generateIndirectTriple("j",
//                                                                          node->child[0]->value, "_"));
//            indirectTripleCodeGenerator(node->child[1], instruction);
//            sprintf(go, "%d", node->child[1]->begin);
//            rewriteTemp(instruction, node->child[0]->end, 2, go);
//            sprintf(go, "%d", 2);
//            rewriteTemp(instruction, node->child[0]->end, 2, "end");
//            rewriteTemp(instruction, node->child[1]->end, 2, "end");
            break;
        case _NOT:
            node->type = 12;
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            node->end = makeNewTemp(instruction, generateIndirectTriple("!",
                                                            node->child[0]->value, "_"));
            sprintf(node->value, "#%d", node->end);
            if (-1 == node->begin) {
                node->begin = node->end;
            }
            break;
        case _ADD:
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->head;
            indirectTripleCodeGenerator(node->child[1], instruction);
            if (-1 == node->begin) {
                node->begin = node->child[1]->head;
            }
            node->end = makeNewTemp(instruction,
                                    generateIndirectTriple("+",
                                                           node->child[0]->value,
                                                           node->child[1]->value));
            sprintf(node->value, "#%d", node->end);
            if (-1 == node->begin) {
                node->begin = node->end;
            }
            break;
        case _MINUS:
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->head;
            indirectTripleCodeGenerator(node->child[1], instruction);
            if (-1 == node->begin) {
                node->begin = node->child[1]->head;
            }
            node->end = makeNewTemp(instruction,
                                    generateIndirectTriple("-",
                                                           node->child[0]->value,
                                                           node->child[1]->value));
            sprintf(node->value, "#%d", node->end);
            if (-1 == node->begin) {
                node->begin = node->end;
            }
            break;
        case _TIMES:
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->head;
            indirectTripleCodeGenerator(node->child[1], instruction);
            if (-1 == node->begin) {
                node->begin = node->child[1]->head;
            }
            node->end = makeNewTemp(instruction,
                                    generateIndirectTriple("*",
                                                           node->child[0]->value,
                                                           node->child[1]->value));
            sprintf(node->value, "#%d", node->end);
            if (-1 == node->begin) {
                node->begin = node->end;
            }
            break;
        case _DIVIDE:
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->head;
            indirectTripleCodeGenerator(node->child[1], instruction);
            if (-1 == node->begin) {
                node->begin = node->child[1]->head;
            }
            node->end = makeNewTemp(instruction,
                                    generateIndirectTriple("/",
                                                           node->child[0]->value,
                                                           node->child[1]->value));
            sprintf(node->value, "#%d", node->end);
            if (-1 == node->begin) {
                node->begin = node->end;
            }
            break;
        case _MOD:
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->head;
            indirectTripleCodeGenerator(node->child[1], instruction);
            if (-1 == node->begin) {
                node->begin = node->child[1]->head;
            }
            node->end = makeNewTemp(instruction,
                                    generateIndirectTriple("%",
                                                           node->child[0]->value,
                                                           node->child[1]->value));
            sprintf(node->value, "#%d", node->end);
            if (-1 == node->begin) {
                node->begin = node->end;
            }
            break;
        case _POW:
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->head;
            indirectTripleCodeGenerator(node->child[1], instruction);
            if (-1 == node->begin) {
                node->begin = node->child[1]->head;
            }
            node->end = makeNewTemp(instruction,
                                    generateIndirectTriple("^",
                                                           node->child[0]->value,
                                                           node->child[1]->value));
            sprintf(node->value, "#%d", node->end);
            if (-1 == node->begin) {
                node->begin = node->end;
            }
            break;
        case _COMMA:
            indirectTripleCodeGenerator(node->child[1], instruction);
            break;
        case _STMT_BODY:
            node->end = makeNewTemp(instruction, generateIndirectTriple("j", "_", "_"));
            for (cursor = 0; cursor < node->size; cursor++) {
                indirectTripleCodeGenerator(node->child[cursor], instruction);
            }
            node->begin = node->child[0]->begin;
            break;
        case _INPUT:
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            node->end = makeNewTemp(instruction,
                                    generateIndirectTriple("in",
                                                           node->child[0]->value, "_"));
            if (-1 == node->begin) {
                node->begin = node->end;
            }
            break;
        case _PRINT_CONTENT:
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            node->end = makeNewTemp(instruction, generateIndirectTriple("out",
                                                            node->child[0]->value, "_"));
            if (-1 == node->begin) {
                node->begin = node->end;
            }
            break;
        case _PRINT:
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            node->end = node->child[0]->end;
            break;
        case _START:
            for (cursor = 0; cursor < node->size; cursor++) {
                indirectTripleCodeGenerator(node->child[cursor], instruction);
            }
            break;
        case _MAIN:
            node->begin = makeNewTemp(instruction,
                                      generateIndirectTriple("j", "_", "_"));
            node->end = makeNewTemp(instruction,
                                    generateIndirectTriple("j", "_", "-1"));
            // Before.
            indirectTripleCodeGenerator(node->child[0], instruction); // Go code blocks.
            // After.
            if (-1 != node->child[0]->begin) {
                sprintf(go, "%d", node->child[0]->begin);
                rewriteTemp(instruction, node->begin, 2, go);
            }
            sprintf(go, "%d", node->end);
            rewriteTemp(instruction, node->child[0]->end, 2, go);
            break;
        case _ID:
            // Searching in symbol table.
            struct Word* word = getWordInfo(node->word);
            node->type = word->type;
            sprintf(node->value, "%s", word->position);
            break;
        case _STRING:
            node->type = 65535;
            sprintf(node->value, "%s", node->word);
            break;
        case _CONST:
            node->type = 1;
            sprintf(node->value, "%s", node->word);
            break;
        default:
            return -2;
    }
    return 0;
}
