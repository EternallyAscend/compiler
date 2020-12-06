//
// Created by MagicBook on 2020/11/15.
//

#ifndef ITEM_H
#define ITEM_H

#define HASH_TABLE_INIT_SIZE 7
#define HASH_CACHE_STACK_SIZE 5 // Must >= 2;
#define STACK_INIT_SIZE 2

#define TYPE_VOID_IST 0
#define TYPE_INT_IST 1
#define TYPE_INT_ARRAY_IST 2
#define TYPE_POINTER_IST 5
// #define TYPE_STRUCT_ITEM_IST 8
// #define TYPE_STRUCT_IST 9
#define TYPE_FUNCTION_IST 10

#define TYPE_INT_IST_STORE 4
#define TYPE_INT_ARRAY_IST_STORE 4
#define TYPE_POINTER_IST_STORE 4
#define TYPE_STRUCT_IST_STORE 4
#define TYPE_FUNCTION_IST_STORE 4

#include <stdio.h>
#include <string>

class Node;
class Tree;

class Item {
	friend class Node;
	friend class Tree;
private:
	std::string name;
	int type;
	int store;
	int position;

	Item(std::string name, int type);
	~Item();
	int isEmptyItem();
	int modifyItemType(int newType);
	int modifyItemStore(int store, int position);
	int getType();
	int getStore();
	int getPosition();
};

#endif // ITEM_H
