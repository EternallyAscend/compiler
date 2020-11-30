//
// Created by MagicBook on 2020/11/15.
//

#include <stdlib.h>
#include <string.h>
#include "table.h"

// Record number with stack and check it with 7.

int symbolType = TYPE_INT_IST;
int* hashTableSizeList = NULL;
unsigned int hashTableSizeListSize = HASH_CACHE_STACK_SIZE;

struct Stack* symbolTableStack = NULL;

//struct Item {
//    char* name;
//    int type;
//    int store;
//    int position;
//};

struct Item* initItem(char* name, int type) {
    struct Item* item = (struct Item*)malloc(sizeof(struct Item));
    item->name = name;
    item->type = type;
    item->store = 0;
    item->position = 0;
    return item;
}

int isEmptyItem(struct Item* item) {
    if (NULL == item) {
        return 1;
    }
    if (NULL == item->name) {
        free(item);
        return 1;
    }
    return 0;
}

int modifyItemStore(struct Item* item, int store, int position) {
    if (isEmptyItem(item)) {
        return 0;
    }
    item->store = store;
    item->position = position;
    return 1;
}

int getNameHash(char* name, int key) {
    int hash = 0;
    int cursor = 0;
    for (; cursor < strlen(name); cursor++) {
        hash += name[cursor];
    }
    return hash % key;
}

int getItemHash(struct Item* item, int key) {
    if (isEmptyItem(item)) {
        return -1;
    }
    return getNameHash(item->name, key);
}

//struct HashTable {
//    struct Item** hashTable;
//    int size;
//    int items;
//};

struct HashTable* initHashTable() {
    struct HashTable* hashTable = (struct HashTable*)malloc(sizeof(struct HashTable));
    hashTable->hashTable = (struct Item**)malloc(sizeof(struct Item*) * HASH_TABLE_INIT_SIZE);
    hashTable->size = HASH_TABLE_INIT_SIZE;
    int cursor = 0;
    for (; cursor < HASH_TABLE_INIT_SIZE; cursor++) {
        hashTable->hashTable[cursor] = NULL;
    }
    hashTable->items = 0;
    return hashTable;
}

int isEmptyHashTable(struct HashTable* hashTable) {
    if (NULL == hashTable) {
        return 1;
    }
    if (NULL == hashTable->hashTable) {
        free(hashTable);
        return 1;
    }
    return 0;
}

int extendHashTable(struct HashTable* hashTable) { //printf("extend hastTable.\n");
    int currentSize = hashTable->size;
    hashTable->size = nextSize(hashTable->size); //printf("%d %d\n", currentSize, hashTable->size);
    struct Item** temporary = hashTable->hashTable;
    hashTable->hashTable = (struct Item**)malloc(sizeof(struct Item*) * hashTable->size);
    int cursor = 0; //printf("items: %d\n", hashTable->items);
    for (; cursor < hashTable->size; cursor++) {
        hashTable->hashTable[cursor] = NULL;
    }
    hashTable->items = 0;
    for (cursor = 0; cursor < currentSize; cursor++) {
        if (NULL != temporary[cursor]) { //printf("%s\n", temporary[cursor]->name);
            insertHashTable(hashTable, temporary[cursor]);
        }
    }
    free(temporary); //printf("Free.\n");
    return 1;
}

int insertHashTable(struct HashTable* hashTable, struct Item* item) {
    if (isEmptyHashTable(hashTable)) {
        return 2;
    }
    int key = getItemHash(item, hashTable->size);
    // Check item whether in symbol table already.
    int cursor = 0;
    while(cursor < hashTable->size) {
        key += cursor * cursor;
        key %= hashTable->size;
        if (NULL == hashTable->hashTable[key]) {
            break;
        }
        else {
            if (0 == strcmp(item->name, hashTable->hashTable[key]->name)) {
                return 0;
            }
        }
        cursor++;
    }
    if(hashTable->items * 2 > hashTable->size) {
        extendHashTable(hashTable);
    }
    key = getItemHash(item, hashTable->size);
    cursor = 0;
    int flag = 1;
    while (flag) {
        while (cursor < hashTable->size) {
            key += cursor * cursor;
            key %= hashTable->size;
            if (NULL == hashTable->hashTable[key]) {
                hashTable->hashTable[key] = item;
                hashTable->items++;
                flag = 0;
                break;
            }
            cursor++;
        }
        if (flag) {
            extendHashTable(hashTable);
        }
    }
    return (int)item;
//    return 1;
}

struct Item* getElementInHashTable(struct HashTable* hashTable, char* name) {
    int key = getNameHash(name, hashTable->size);
    int cursor = 0;
    while(cursor < hashTable->size) {
        key += cursor * cursor;
        key %= hashTable->size;
        if (NULL == hashTable->hashTable[key]) {
            return NULL;
        }
        else {
            if (0 == strcmp(name, hashTable->hashTable[key]->name)) {
                return hashTable->hashTable[key];
            }
        }
        cursor++;
    }
    return NULL;
}

int elementInHashTable(struct HashTable* hashTable, char* name) {
    return NULL == getElementInHashTable(hashTable, name);
}

int destroyHashTable(struct HashTable* hashTable) {
    if(isEmptyHashTable(hashTable)) {
        return 2;
    }
    int cursor = 0;
    for (; cursor < hashTable->size; cursor++) {
        free(hashTable->hashTable[cursor]);
    }
    return destroyHashTableOnly(hashTable);
}

int destroyHashTableOnly(struct HashTable* hashTable) {
    if(isEmptyHashTable(hashTable)) {
        return 2;
    }
    free(hashTable->hashTable);
    free(hashTable);
    return 1;
}

//struct Stack {
//    struct HashTable** stack;
//    int tail;
//    int size;
//};

struct Stack* initStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->stack = (struct HashTable**)malloc(sizeof(struct HashTable*) * STACK_INIT_SIZE);
    stack->tail = 0;
    stack->size = STACK_INIT_SIZE;
    pushStack(stack);
    return stack;
}

int isEmptyStack(struct Stack* stack) {
    if (NULL == stack) {
        return 1;
    }
    if (NULL == stack->stack) {
        free(stack);
        return 1;
    }
    return 0;
}

int pushStack(struct Stack* stack) {
    if (isEmptyStack(stack)) {
        return 2;
    }
    struct HashTable* newLayer = initHashTable();
    if (stack->tail == stack->size) {
        extendStack(stack);
    }
    stack->stack[stack->tail++] = newLayer;
    return 1;
}

int popStack(struct Stack* stack) {
    if (isEmptyStack(stack)) {
        return 2;
    }
    if (0 != stack->tail) {
        destroyHashTable(stack->stack[--stack->tail]);
        return 1;
    }
    else {
        return 0;
    }
}

int extendStack(struct Stack* stack) {
    if (isEmptyStack(stack)) {
        return 2;
    }
    struct HashTable** temporary = (struct HashTable**)malloc(sizeof(struct HashTable*) * stack->size * 2);
    int cursor = 0;
    for (; cursor < stack->tail; cursor++) {
        temporary[cursor] = stack->stack[cursor];
    }
    free(stack->stack);
    stack->stack = temporary;
    stack->size *= 2;
    return 1;
}

int destroyStack(struct Stack* stack) {
    if (isEmptyStack(stack)) {
        return 2;
    }
    int cursor = 0;
    for (; cursor < stack->tail; cursor++) {
        destroyHashTable(stack->stack[cursor]);
    }
    return destroyStackOnly(stack);
}

int destroyStackOnly(struct Stack* stack) {
    if (isEmptyStack(stack)) {
        return 2;
    }
    free(stack->stack);
    free(stack);
    return 1;
}

int launchTable() {
    if (isEmptyStack(symbolTableStack)) {
        symbolTableStack = initStack();
    }
    if (NULL == hashTableSizeList) {
        hashTableSizeList = (int *) malloc(sizeof(int) * HASH_CACHE_STACK_SIZE);
        int temp, cursor;
        hashTableSizeList[0] = 2;
        hashTableSizeList[1] = 2;
        for (temp = cursor = 2; cursor < HASH_CACHE_STACK_SIZE; cursor++) {
            hashTableSizeList[cursor] = temp = nextPrime(temp);
        }
        hashTableSizeList[0] = HASH_CACHE_STACK_SIZE;
    }
    return 0;
}

int push() {
    return pushStack(symbolTableStack);
}

int pop() {
    return popStack(symbolTableStack);
}

int setType(int type) {
    return symbolType = type;
}

int add(char* name) {
    return insertHashTable(symbolTableStack->stack[symbolTableStack->tail - 1], initItem(name, symbolType));
}

int search(char* name) {
    return NULL == pull(name);
}

int functionSearch(char* name) {
    return NULL == functionPull(name);
}

struct Item* pull(char* name) {
    struct Item* result = NULL;
    int cursor = symbolTableStack->tail;
    while (cursor) {
        result = getElementInHashTable(symbolTableStack->stack[cursor - 1], name);
        if (NULL != result) {
            return result;
        }
        cursor--;
    }
    return result;
}

struct Item* functionPull(char* name) {
    struct Item* result = getElementInHashTable(symbolTableStack->stack[symbolTableStack->tail - 1], name);
    if (NULL == result) {
        result = getElementInHashTable(symbolTableStack->stack[0], name);
    }
    return result;
}

int stopTable() {
    destroyStack(symbolTableStack);
    free(hashTableSizeList);
    return 0;
}

int nextPrime(int current) {
    int cursor;
    int target = current;
    int flag = 1;
    while(flag) {
        cursor = 1;
        target++;
        while(cursor < hashTableSizeList[0]) {
            if (0 == target % hashTableSizeList[cursor]) {
                break;
            }
            else if (hashTableSizeList[cursor] * hashTableSizeList[cursor] > target) {
                flag = 0;
                break;
            }
            cursor++;
        }
        if (cursor == hashTableSizeList[0]) {
            cursor = hashTableSizeList[cursor - 1];
            int available = 1;
            while(cursor * cursor <= target) {
                if (0 == target % cursor) {
                    available = 0;
                    break;
                }
                cursor++;
            }
            if (available) {
                flag = 0;
            }
        }
    }
    return target;
}

// Current must in hashTableSizeList here.
// Binary Searching Later.
int nextSize(int current) {
    int cursor = 1;
    int target = current;

    // Binary Searching.
    for (; cursor < hashTableSizeList[0]; cursor++) {
        if (hashTableSizeList[cursor] > target) {
            target = hashTableSizeList[cursor];
            return target;
        }
    }

    target = nextPrime(current);
    if (hashTableSizeList[0] == hashTableSizeListSize) {
        int* temporary = (int*)malloc(sizeof(int) * hashTableSizeListSize * 2);
        for (cursor = 0; cursor < hashTableSizeList[0]; cursor++) {
            temporary[cursor] = hashTableSizeList[cursor];
        }
        free(hashTableSizeList);
        hashTableSizeList = temporary;
        hashTableSizeListSize *= 2;
    }
    hashTableSizeList[hashTableSizeList[0]++] = target;
    return target;
}
