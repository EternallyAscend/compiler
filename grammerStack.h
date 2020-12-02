#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SENTENCE_MAX_LENGTH 64

typedef struct GrammerItem {
    struct GrammerItem *front = NULL, *next = NULL;
    char sentence[SENTENCE_MAX_LENGTH];
    int level;
} grammerItem;

grammerItem* createNode(int level, const char* sentence) {
    // create a grammer item, the item need to destroy manually by function: destroyNode(grammerItem* node).
    grammerItem* newNode = (grammerItem*)malloc(sizeof(grammerItem));
    strcpy(newNode->sentence, sentence);
    newNode->level = level;
    return newNode;
}

void destroyNode(grammerItem* node){
    // free the memory of node created by the function: createNode(int level, const char* sentence).
    free(node);
}

grammerItem* push_grammer_stack(grammerItem* target, grammerItem* tail) {
    // push the new node into the stack, return the new node, at the same time the new tail.
    tail->next = target;
    target->front = tail;
    return target;
}

grammerItem* pop_grammer_stack(grammerItem* tail) {
    // pop the tail node and return the new node. if it is the last node in the stack, return NULL.
    if (tail->front == NULL) return NULL;
    grammerItem* front = tail->front;
    front->next = NULL;
    return front;
}