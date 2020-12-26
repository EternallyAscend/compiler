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
    switch (node->opt) {
        case _ERROR:
            return -1;
        case _VOID:
            node->type = 0;
            break;
        case _INT:
            node->type = 1;
            break;
        case _FOR:

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
            break;
        case _BREAK:
            break;
        case _IF:
            break;
        case _ELSE:
            break;
        case _IF_STMT:
            break;
        case _IF_CONDITION:
            break;
        case _RETURN:
            break;
        case _ADDRESS:
            break;
        case _ARRAY:
            break;
        case _LPRP:
            break;
        case _LP:
            break;
        case _RP:
            break;
        case _SLPRP:
            break;
        case _LSP:
            break;
        case _RSP:
            break;
        case _BLPRP:
            break;
        case _LBP:
            break;
        case _RBP:
            break;
        case _LOOP:
            break;
        case _POINTER:
            break;
        case _ASSIGN:
            node->type = 12;
            break;
        case _DECLARATION:
            break;
        case _ARGUMENT_DECLARATION_LIST:
            break;
        case _DECLARATION_BODY:
            break;
        case _ARGUMENT_DECLARATION_UNIT:
            break;
        case _EQUAL:
            node->type = 12;
            break;
        case _NOTEQUAL:
            node->type = 12;
            break;
        case _GT:
            node->type = 12;
            indirectTripleCodeGenerator(node->child[0], instruction);
            indirectTripleCodeGenerator(node->child[1], instruction);
            makeNewTemp(instruction, generateIndirectTriple(">",
                                                            node->child[0]->value,
                                                            node->child[1]->value));
            break;
        case _LT:
            node->type = 12;
            indirectTripleCodeGenerator(node->child[0], instruction);
            indirectTripleCodeGenerator(node->child[1], instruction);
            makeNewTemp(instruction, generateIndirectTriple("<",
                                                            node->child[0]->value,
                                                            node->child[1]->value));
            break;
        case _GE:
            node->type = 12;
            indirectTripleCodeGenerator(node->child[0], instruction);
            indirectTripleCodeGenerator(node->child[1], instruction);
            makeNewTemp(instruction, generateIndirectTriple(">=",
                                                            node->child[0]->value,
                                                            node->child[1]->value));
            break;
        case _LE:
            node->type = 12;
            indirectTripleCodeGenerator(node->child[0], instruction);
            indirectTripleCodeGenerator(node->child[1], instruction);
            makeNewTemp(instruction, generateIndirectTriple("<=",
                                                            node->child[0]->value,
                                                            node->child[1]->value));
            break;
        case _AND:
            node->type = 12;
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = makeNewTemp(instruction, generateIndirectTriple("j",
                                                                          node->child[0]->value, "_"));
            makeNewTemp(instruction, generateIndirectTriple("j", "_", "_"));
            indirectTripleCodeGenerator(node->child[1], instruction);
            sprintf(go, "%d", node->child[1]->begin);
            rewriteTemp(instruction, node->begin, 2, go);

            rewriteTemp(instruction, node->child[0]->end, 2, "end");
            rewriteTemp(instruction, node->child[1]->end, 2, "end");
            break;
        case _OR:
            node->type = 12;
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = makeNewTemp(instruction, generateIndirectTriple("j",
                                                                          node->child[0]->value, "_"));
            indirectTripleCodeGenerator(node->child[1], instruction);
            sprintf(go, "%d", node->child[1]->begin);
            rewriteTemp(instruction, node->child[0]->end, 2, go);
            sprintf(go, "%d", 2);
            rewriteTemp(instruction, node->child[0]->end, 2, "end");
            rewriteTemp(instruction, node->child[1]->end, 2, "end");
            break;
        case _NOT:
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->type = 12;
            makeNewTemp(instruction, generateIndirectTriple("!",
                                                            node->child[0]->value, "_"));
            node->trueList = node->child[0]->falseList;
            node->falseList = node->child[0]->trueList;
            break;
        case _ADD:
            indirectTripleCodeGenerator(node->child[0], instruction);
            indirectTripleCodeGenerator(node->child[1], instruction);
            node->end = makeNewTemp(instruction,
                                    generateIndirectTriple("+",
                                                           node->child[0]->value,
                                                           node->child[1]->value));
            break;
        case _MINUS:
            indirectTripleCodeGenerator(node->child[0], instruction);
            indirectTripleCodeGenerator(node->child[1], instruction);
            node->end = makeNewTemp(instruction,
                                    generateIndirectTriple("-",
                                                           node->child[0]->value,
                                                           node->child[1]->value));
            break;
        case _TIMES:
            indirectTripleCodeGenerator(node->child[0], instruction);
            indirectTripleCodeGenerator(node->child[1], instruction);
            node->end = makeNewTemp(instruction,
                                    generateIndirectTriple("*",
                                                           node->child[0]->value,
                                                           node->child[1]->value));
            break;
        case _DIVIDE:
            indirectTripleCodeGenerator(node->child[0], instruction);
            indirectTripleCodeGenerator(node->child[1], instruction);
            node->end = makeNewTemp(instruction,
                                    generateIndirectTriple("/",
                                                           node->child[0]->value,
                                                           node->child[1]->value));
            break;
        case _MOD:
            indirectTripleCodeGenerator(node->child[0], instruction);
            indirectTripleCodeGenerator(node->child[1], instruction);
            node->end = makeNewTemp(instruction,
                                    generateIndirectTriple("%",
                                                           node->child[0]->value,
                                                           node->child[1]->value));
            break;
        case _POW:
            indirectTripleCodeGenerator(node->child[0], instruction);
            indirectTripleCodeGenerator(node->child[1], instruction);
            node->end = makeNewTemp(instruction,
                                    generateIndirectTriple("^",
                                                           node->child[0]->value,
                                                           node->child[1]->value));
            break;
        case _COMMA:
            indirectTripleCodeGenerator(node->child[1], instruction);
            break;
        case _STMT_BODY:
            int cursor = 0;
            for (; cursor < node->size; cursor++) {
                indirectTripleCodeGenerator(node->child[cursor], instruction);
            }

            break;
        case _INPUT:
            node->end = makeNewTemp(instruction,
                                    generateIndirectTriple("in",
                                                           node->child[0]->value, "_"));
            break;
        case _PRINT_CONTENT:
            indirectTripleCodeGenerator(node->child[0], instruction);
            makeNewTemp(instruction, generateIndirectTriple("out",
                                                            node->child[0]->value, "_"));
            break;
        case _PRINT:
            indirectTripleCodeGenerator(node->child[0], instruction);
            break;
        case _MAIN:
            node->begin = makeNewTemp(instruction,
                                      generateIndirectTriple("j", "_", "_"));
            node->end = makeNewTemp(instruction,
                                    generateIndirectTriple("j", "_", "-1"));
            // Before.
            indirectTripleCodeGenerator(node->child[0], instruction); // Go code blocks.
            // After.
            char go[64];
            if (0 < node->child[0]->begin) {
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
