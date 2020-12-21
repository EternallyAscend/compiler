//
// Created by MagicBook on 2020/12/14.
//

#ifndef INDIRECTTRIPLE_BACKPATCHING_H
#define INDIRECTTRIPLE_BACKPATCHING_H

struct BackPatchingSet {
    int* id;
    int size;
    int tail;
};

int isEmptyBackPatchingSet(struct BackPatchingSet* backPatchingSet);

struct BackPatchingSet* generateBackPatchingSet(int id);

int searchElementInID(struct BackPatchingSet* backPatchingSet, int target);

int appendElementIntoID(struct BackPatchingSet* backPatchingSet, int target);

int mergeBackPatchingSet(struct BackPatchingSet* me, struct BackPatchingSet* append);

struct BackPatchingSet* mergeGenerateBackPatchingSet(struct BackPatchingSet* left, struct BackPatchingSet* right);

int destroyBackPatchingSet(struct BackPatchingSet* backPatchingSet);

struct BackPatchingLayer {
    char** commandList;
    int size;
    int tail;
};

int isEmptyBackPatchingLayer(struct BackPatchingLayer* backPatchingLayer);

struct BackPatchingLayer* generateBackPatchingLayer();

int makeList(struct BackPatchingLayer* backPatchingLayer, int nextInStr);

//int mergeBackPatchingCommand();

int generateCommand(struct BackPatchingLayer* backPatchingLayer, int index, char* command);

int makeAndGenerateBackPatchingLayerCommand(struct BackPatchingLayer* backPatchingLayer, char* command);

int destroyBackPatchingLayer(struct BackPatchingLayer* backPatchingLayer);

#endif //INDIRECTTRIPLE_BACKPATCHING_H
