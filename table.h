//
// Created by MagicBook on 2020/11/15.
//

#ifndef TABLE_TABLE_H
#define TABLE_TABLE_H

#define HASH_TABLE_INIT_SIZE 7
#define HASH_CACHE_STACK_SIZE 5 // Must >= 2;
#define STACK_INIT_SIZE 2

#include <stdio.h>

//struct Scope {
//    struct Scope* parent;
//    int layer;
//};

struct Item {
    char* name;
    int type;
    int store;
//    struct Scope* scope;
    int position;
//    int visible;
//    int constable;
//    char* other;
};

struct Item* initItem(char* name, int type);

int isEmptyItem(struct Item* item);

int modifyItemStore(struct Item* item, int store, int position);

int getNameHash(char* name, int key);

int getItemHash(struct Item* item, int key);

//int destroyItem(struct Item* item);

//int destroyItemOnly(struct Item* item);

struct HashTable {
    struct Item** hashTable;
    int size;
    int items;
};

struct HashTable* initHashTable();

int isEmptyHashTable(struct HashTable* hashTable);

int extendHashTable(struct HashTable* hashTable);

int insertHashTable(struct HashTable* hashTable, struct Item* item);

struct Item* getElementInHashTable(struct HashTable* hashTable, char* name);

int elementInHashTable(struct HashTable* hashTable, char* name);

//int removeHashTable(struct HashTable* hashTable, char* name);

int destroyHashTable(struct HashTable* hashTable);

int destroyHashTableOnly(struct HashTable* hashTable);

struct Stack {
    struct HashTable** stack;
    int tail;
    int size;
};

struct Stack* initStack();

int isEmptyStack(struct Stack* stack);

int pushStack(struct Stack* stack);

int popStack(struct Stack* stack);

int extendStack(struct Stack* stack);

int destroyStack(struct Stack* stack);

int destroyStackOnly(struct Stack* stack);

int launchTable();

int push();

int pop();

int add(char* name, int type);

int search(char* name);

int functionSearch(char* name);

struct Item* pull(char* name);

struct Item* functionPull(char* name);

int stopTable();

int nextPrime(int current);

int nextSize(int current);

//struct Table {
//
//};
//
//struct Table* initTable();
//
//int destroyTable(struct Table* table);
//
//int destroyTableOnly(struct Table* table);
//
//
//struct TableTree {
//    struct Table* root;
//};
//
//struct TableTree* initTableTree();
//
//struct TableTree* readTableTreeFromFile(const char* path);
//
//int destroyTableTree(struct TableTree* tableTree);
//
//int writeTableTree(struct TableTree* tableTree, const char* path);
//
//int insertTableToTree(struct TableTree* tableTree, struct Table* table);


#endif //TABLE_TABLE_H
