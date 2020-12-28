#ifndef GRAMMERTREE_H
#define GRAMMERTREE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <vector>
#include "file.h"
#include "pointer.h"
#define MAX_CHILDREN_NUM 10
#define MAX_SENTENCE_LENGTH 32
#define MAX_OUTPUT_LENGTH 128
#define TERMINAL 1
#define NON_TERMINAL 0

typedef struct GrammerTree{
    int childLength;
    struct GrammerTree **child;
    struct GrammerTree *parent;
    // struct GrammerTree *child[MAX_CHILDREN_NUM];
    // std::vector<struct GrammerTree*> child(MAX_CHILDREN_NUM); 
    int size;
    int index;
    int isTerminal;
    char word[MAX_SENTENCE_LENGTH];
    char grammer[MAX_SENTENCE_LENGTH];

    int opt;
    int head;
    char* operators;
    int type;
    int isNotEmpty;
    char* value;
    int begin;
    int end;
    int trueList;
    int falseList;

    PtrInfo* ptrType;
    
} grammerTree, *GrammarTree;

int push_child(grammerTree* parent, grammerTree* node){
    // if (parent->size >= 9) return 0;
    // parent->child[parent->size] = node;

    // parent->child.push_back(node);

    if (parent->size == parent->childLength) {
        struct GrammerTree** newList = (struct GrammerTree**)malloc(sizeof(struct GrammerTree*)*2*parent->size);
        int cursor = 0;
        for (; cursor < parent->size; cursor++) {
            newList[cursor] = parent->child[cursor];
        }
        free(parent->child);
        parent->child = newList;
        parent->childLength = 2 * parent->size;
    }
    parent->child[parent->size] = node;

    node->parent = parent;
    return parent->size++;
}

GrammarTree getChildInGrammarTree(GrammarTree node, int index) {
    return node->child[index];
}

grammerTree* createGrammerNode(int isTerminal, const char* word, const char* grammer) {
    grammerTree* newNode = (grammerTree*)(malloc(sizeof(grammerTree)));
    newNode->childLength = 4;
    newNode->child = (struct GrammerTree**)malloc(sizeof(struct GrammerTree*)*newNode->childLength);
    newNode->size = 0;
    newNode->parent = NULL;
    newNode->index = -1;
    newNode->isTerminal = isTerminal;
    strcpy(newNode->word, word);
    strcpy(newNode->grammer, grammer);

    newNode->opt = -1;
    newNode->head = -1;
    newNode->operators = (char*)malloc(sizeof(char)*16);
    sprintf(newNode->operators, "Default OP."); // "Default Operator.";
    newNode->type = -1;
    newNode->isNotEmpty = 1;
    newNode->value = (char*)malloc(sizeof(char)*128); 
    sprintf(newNode->value, "No Value."); // "No value.";
    newNode->begin = -1;
    newNode->end = -1;
    newNode->trueList = -1;
    newNode->falseList = -1;

    newNode->ptrType = NULL; // 保证当type>1时，该值不为空，指向一个描述类型的数据（在ID处需从表中获取）

    return newNode;
}

void traversal(void func(grammerTree*), grammerTree* root) {
    for (int i = 0; i < root->size; i++) {
        traversal(func, root->child[i]);
    }
    func(root);
}

void freeGrammerNode(grammerTree* node) {
    if(node != NULL){
        if (NULL != node->operators) {
            free(node->operators);
        }
        if (NULL != node->value) {
            free(node->value);
        }
        if (NULL != node->child) {
            free(node->child);
        }
        free(node);
        node = NULL;
    }    
}

void freeGrammerTree(grammerTree* root) {
    traversal(freeGrammerNode, root);
}

void printGrammerNode(grammerTree* node) {
    static int word_pos = 0;
    node->index = word_pos++;
    char str[MAX_OUTPUT_LENGTH];
    sprintf(str, "%-5d: \t%-25s\t%-18s\t", node->index, node->grammer, node->word);
    char child[1024] = "child: ";
    for(int i = 0; i < node->size; i++) {
        sprintf(child, "%s %d", child, node->child[i]->index);
    }
    strcat(str, child);
    strcat(str, "\n");
    // output str
    appendYACC(str);
    ///* Temporary output all value for nodes.
    // char* temporary = (char*)malloc(sizeof(char)*1024);
    // sprintf(temporary, "OP: %s, Type: %d, Value: %s, Begin: %d, End: %d, True: %d, False: %d.\n",
    //  node->operators,
    //   node->type,
    //    node->value,
    //     node->begin,
    //      node->end,
    //       node->trueList,
    //        node->falseList);
    // appendYACC(temporary);
    // free(temporary);
    //*/
}

void printGrammerTree(grammerTree* root) {
    traversal(printGrammerNode, root);
}

int findSelfPos(grammerTree* node){
    grammerTree* parent = node->parent;
    for (int i = 0; i < parent->size; i++) {
        if (parent->child[i] == node) return i;
    }
    return -1;
}

void adjustOptNode(grammerTree* optNode) {
    //used to trans operator node
    grammerTree* parent = optNode->parent;
    int pos;
    if((pos = findSelfPos(optNode)) == -1) return;
    grammerTree* node = parent->child[pos - 1];
    parent->child[pos - 1] = optNode;
    parent->size--;
    optNode->child[1] = optNode->child[0];
    optNode->child[0] = node;
    node->parent = optNode;
    optNode->size++;
}

#endif // GRAMMERTREE_H
