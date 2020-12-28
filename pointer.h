#ifndef POINTER_H
#define POINTER_H

#include<unordered_map>
#include<string>
#include<vector>

// typedef enum {
//     ARY,
//     PTR
// } PtrType;

typedef struct PtrInfos {
    // PtrType type;
    int dimension;
    std::vector<int> width;
} PtrInfo;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


PtrInfo* createPtrInfo();

int getPtrDimension(PtrInfo* info);

void registPtr(unsigned int id, PtrInfo* info);

int setArrayWidth(PtrInfo* info, int _width);

PtrInfo* getPtrInfo(unsigned int id);

int getArrayWidth(PtrInfo* info, int _dimension);

void destroyPtrInfo(PtrInfo* info);

void ptrTableClear();
//int extendDimension(const char* id, int _width);

unsigned int calculateStore(PtrInfo* info);

PtrInfo* findLowerPtr(PtrInfo* upper);


#ifdef __cplusplus
}
#endif // __cplusplus


#endif
