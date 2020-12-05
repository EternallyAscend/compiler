#ifndef GRAMMERTREE_H
#define GRAMMERTREE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "file.h"
#define MAX_CHILDREN_NUM 10
#define MAX_SENTENCE_LENGTH 32
#define MAX_OUTPUT_LENGTH 128
#define TERMINAL 1
#define NON_TERMINAL 0

typedef struct GrammerTree{
    struct GrammerTree *parent;
    struct GrammerTree *child[MAX_CHILDREN_NUM];
    int size;
    int index;
    int isTerminal;
    char word[MAX_SENTENCE_LENGTH];
    char grammer[MAX_SENTENCE_LENGTH];
} grammerTree;

int push_child(grammerTree* parent, grammerTree* node){
    if (parent->size >= 9) return 0;
    parent->child[parent->size] = node;
    node->parent = parent;
    return parent->size++;
}

grammerTree* createGrammerNode(int isTerminal, const char* word, const char* grammer) {
    grammerTree* newNode = (grammerTree*)(malloc(sizeof(grammerTree)));
    newNode->size = 0;
    newNode->parent = NULL;
    newNode->index = -1;
    newNode->isTerminal = isTerminal;
    strcpy(newNode->word, word);
    strcpy(newNode->grammer, grammer);
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
    sprintf(str, "%-4d: \t%-10s\t%-18s\t", node->index, node->grammer, node->word);
    char child[24] = "child: ";
    for(int i = 0; i < node->size; i++) {
        sprintf(child, "%s %d", child, node->child[i]->index);
    }
    strcat(str, child);
    strcat(str, "\n");
    // output str
    appendYACC(str);
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