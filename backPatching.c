//
// Created by MagicBook on 2020/12/14.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "backPatching.h"

//struct BackPatchingSet {
//    int* id;
//    int size;
//    int tail;
//};

int isEmptyBackPatchingSet(struct BackPatchingSet* backPatchingSet) {
    if (NULL == backPatchingSet) {
        return 1;
    }
    else if (NULL == backPatchingSet->id) {
        free(backPatchingSet);
        return 2;
    }
    return 0;
}

struct BackPatchingSet* generateBackPatchingSet(int id) {
    struct BackPatchingSet* backPatchingSet = (struct BackPatchingSet*)malloc(sizeof(struct BackPatchingSet));
    backPatchingSet->id = (int*)malloc(sizeof(int));
    backPatchingSet->id[0] = id;
    backPatchingSet->tail = 1;
    backPatchingSet->size = 1;
    return backPatchingSet;
}

int searchElementInID(struct BackPatchingSet* backPatchingSet, int target) {
    if (isEmptyBackPatchingSet(backPatchingSet)) {
        return -1;
    }
    int cursor = 0;
    for (; cursor < backPatchingSet->tail; cursor++) {
        if (target == backPatchingSet->id[cursor]) {
            return 1;
        }
    }
    return 0;
}

int appendElementIntoID(struct BackPatchingSet* backPatchingSet, int target) {
    if (searchElementInID(backPatchingSet, target)) {
        return 0;
    }
    if (backPatchingSet->tail == backPatchingSet->size) {
        int* temporary = backPatchingSet->id;
        backPatchingSet->id = (int*)malloc(sizeof(int)*backPatchingSet->size*2);
        int cursor = 0;
        for (; cursor < backPatchingSet->size; cursor++) {
            backPatchingSet->id[cursor] = temporary[cursor];
        }
        free(temporary);
        backPatchingSet->size *= 2;
    }
    return backPatchingSet->id[backPatchingSet->tail++] = target;
}

int mergeBackPatchingSet(struct BackPatchingSet* me, struct BackPatchingSet* append) {
    if (isEmptyBackPatchingSet(append)) {
        return 0;
    }
    int flag = 1;
    int cursor = 0;
    for (; cursor < append->tail; cursor++) {
        flag = flag && appendElementIntoID(me, append->id[cursor]);
    }
    return flag;
}

struct BackPatchingSet* mergeGenerateBackPatchingSet(struct BackPatchingSet* left, struct BackPatchingSet* right) {
    struct BackPatchingSet* backPatchingSet = (struct BackPatchingSet*)malloc(sizeof(struct BackPatchingSet));
    backPatchingSet->tail = left->tail;
    backPatchingSet->size = backPatchingSet->tail * 2;
    backPatchingSet->id = (int*)malloc(sizeof(int) * backPatchingSet->size);
    int cursor = 0;
    for (; cursor < left->tail; cursor++) {
        backPatchingSet->id[cursor] = left->id[cursor];
    }
    mergeBackPatchingSet(backPatchingSet, right);
    return backPatchingSet;
}

int destroyBackPatchingSet(struct BackPatchingSet* backPatchingSet) {
    if (isEmptyBackPatchingSet(backPatchingSet)) {
        return 0;
    }
    free(backPatchingSet->id);
    free(backPatchingSet);
    return 1;
}

//struct BackPatchingLayer {
//    char** commandList;
//    int size;
//    int tail;
//};

int isEmptyBackPatchingLayer(struct BackPatchingLayer* backPatchingLayer) {
    if (NULL == backPatchingLayer) {
        return 1;
    }
    if (NULL == backPatchingLayer->commandList) {
        free(backPatchingLayer);
        return 2;
    }
    return 0;
}

struct BackPatchingLayer* generateBackPatchingLayer() {
    struct BackPatchingLayer* backPatchingLayer = (struct BackPatchingLayer*)malloc(sizeof(struct BackPatchingLayer));
    backPatchingLayer->commandList = (char**)malloc(sizeof(char*)*256);
    backPatchingLayer->size = 256;
    backPatchingLayer->tail = 0;
    return backPatchingLayer;
}

int makeList(struct BackPatchingLayer* backPatchingLayer, int nextInStr) {
    if (isEmptyBackPatchingLayer(backPatchingLayer)) {
        return -1;
    }
    if (backPatchingLayer->tail == backPatchingLayer->size) {
        char** temporary = backPatchingLayer->commandList;
        backPatchingLayer->commandList = (char**)malloc(sizeof(char*)*backPatchingLayer->size*2);
        int cursor = 0;
        for (; cursor < backPatchingLayer->tail; cursor++) {
            backPatchingLayer->commandList[cursor] = temporary[cursor];
        }
        free(temporary);
        backPatchingLayer->size *= 2;
    }
    backPatchingLayer->commandList[backPatchingLayer->tail++] = NULL;
    return backPatchingLayer->tail - 1;
}

//int mergeBackPatchingCommand();

int generateCommand(struct BackPatchingLayer* backPatchingLayer, int index, char* command) {
    if (isEmptyBackPatchingLayer(backPatchingLayer)) {
        return -1;
    }
    if (index >= backPatchingLayer->tail) {
        return -2;
    }
    return (int)(backPatchingLayer->commandList[index] = command);
}

int appendCommand(struct BackPatchingLayer* backPatchingLayer, int index, char* command) {
    if (isEmptyBackPatchingLayer(backPatchingLayer)) {
        return -1;
    }
    if (index >= backPatchingLayer->tail) {
        return -2;
    }
    return (int)(strcat(backPatchingLayer->commandList[index], command));
}

int makeAndGenerateBackPatchingLayerCommand(struct BackPatchingLayer* backPatchingLayer, char* command) {
    if (isEmptyBackPatchingLayer(backPatchingLayer)) {
        return -1;
    }
    if (backPatchingLayer->tail == backPatchingLayer->size) {
        char** temporary = backPatchingLayer->commandList;
        backPatchingLayer->commandList = (char**)malloc(sizeof(char*)*backPatchingLayer->size*2);
        int cursor = 0;
        for (; cursor < backPatchingLayer->tail; cursor++) {
            backPatchingLayer->commandList[cursor] = temporary[cursor];
        }
        free(temporary);
        backPatchingLayer->size *= 2;
    }
    (backPatchingLayer->commandList[backPatchingLayer->tail++] = command);
    return backPatchingLayer->tail - 1;
}

int destroyBackPatchingLayer(struct BackPatchingLayer* backPatchingLayer) {
    if (isEmptyBackPatchingLayer(backPatchingLayer)) {
        return 0;
    }
    free(backPatchingLayer->commandList);
    free(backPatchingLayer);
    return 1;
}
