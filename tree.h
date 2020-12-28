//
// Created by MagicBook on 2020/11/15.
//

#ifndef TREE_H
#define TREE_H

#include "item.h"
#include <vector>
#include <unordered_map>

class Node {
	friend class Tree;
private:
	Node* parent;
	std::unordered_map<std::string, Item*>* hashMap;
	int cursor;
	std::vector<Node*>* children;

	Node(Node* parent);
	~Node();
	int addItem(Item* item);
	int addChild(Node* child);
	int countItem(const char* name);
	Item* getItem(const char* name);
	Node* getNextChild();
};

class Tree {
private:
	Node* root;
	Node* current;
	int currentType;

	Item* getItemGlobal(const char* name);
public:
	Tree();
	~Tree();

	int pushScope(int creator);
	int popScope();
	int addWord(const char* name);
	int searchWord(const char* name);
	int searchWordGlobal(const char* name);
	int searchWordInFunction(const char* name);
	int setType(const char* name, int type);
	// int setStore(const char* name, int store, int position);
	int setStore(const char* name, int store, char* position);
	int setTypeFunction(const char* name, int type);
	// int setStoreFunction(const char* name, int store, int position);
	int setStoreFunction(const char* name, int store, char* position);
	int setCurrentType(int type);
	int restart();
	struct Word* getWordGlobal(const char* name);
	struct Word* getWordFunction(const char* name);
};

#endif // TREE_H
