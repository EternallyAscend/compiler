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
	int countItem(std::string name);
	Item* getItem(std::string name);
	Node* getNextChild();
};

class Tree {
private:
	Node* root;
	Node* current;
	int currentType;

	Item* getItemGlobal(std::string name);
public:
	Tree();
	~Tree();

	int pushScope(int creator);
	int popScope();
	int addWord(std::string name);
	int searchWord(std::string name);
	int searchWordGlobal(std::string name);
	int searchWordInFunction(std::string name);
	int setType(std::string name, int type);
	int setStore(std::string name, int store, int position);
	int setTypeFunction(std::string name, int type);
	int setStoreFunction(std::string name, int store, int position);
	int setCurrentType(int type);
	int restart();
	struct Word* getWordGlobal(std::string name);
	struct Word* getWordFunction(std::string name);
};

#endif TREE_H // TREE_H
