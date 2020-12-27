#include "pointer.h"
#include "item.h"


PtrInfo* createPntInfo() {
    PtrInfo* newInfo = (PtrInfo*)malloc(sizeof(PtrInfo));
    newInfo->dimension = 0;
    return newInfo;
}

void registPtr(unsigned int id, PtrInfo* info) {
    if(getPtrInfo(id) == NULL)
        PtrTable.insert(std::pair<unsigned int, PtrInfo*>(id, info));
}

int setArrayWidth(PtrInfo* info, int _width) {
    if(info == NULL)
        return -1;
    info->width.push_back(_width);
    info->dimension = info->width.size();
    return info->dimension;
}

 PtrInfo* getPtrInfo(unsigned int id) {
    auto iter = PtrTable.find(id);
    if(iter == PtrTable.end())
        return NULL;
    return iter->second;
 }

 int getArrayWidth(PtrInfo* info, int _dimension) {
    if(info == NULL || info->dimension < _dimension)
        return -1;
    return info->width[_dimension];
 }

 void ptrTableClear(){
    auto iter = PtrTable.begin();
    while(iter != PtrTable.end()) {
        free(iter->second);
    }
    PtrTable.clear();
 }

 void destroyPtrInfo(PtrInfo* info) {
    free(info);
 }

 unsigned int calculateStore(PtrInfo* info) {
    auto iter = info->width.rbegin();
    bool ptrmeta = false;
    unsigned int store = 1;
    while (iter != info->width.rend()){
        if(*iter == -1){
            ptrmeta = true;
            continue;
        }
        store *= *iter;
    }
    if (ptrmeta) {
        store *= TYPE_POINTER_IST_STORE;
    }
    else {
        store *= TYPE_INT_IST_STORE;
    }
    return store;
 }

 
PtrInfo* findLowerPtr(PtrInfo* upper) {
    PtrInfo* lowerPtr = (PtrInfo*)malloc(sizeof(PtrInfo));
    lowerPtr->dimension = upper->dimension - 1;
    lowerPtr->width = std::vector<int>(upper->width);
    lowerPtr->width.erase(lowerPtr->width.begin());
    return lowerPtr;
}


int getPtrDimension(PtrInfo* info) {
    return info->dimension;
}