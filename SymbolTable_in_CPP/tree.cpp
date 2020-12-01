//
// Created by MagicBook on 2020/11/15.
//

#include "tree.h"

// Node ============================================================

Node::Node(Node* parent) {
	this->parent = parent;
	this->hashMap = new std::unordered_map<std::string, Item*>();
	this->cursor = 0;
	this->children = new std::vector<Node*>();
}

Node::~Node() {
	for (auto iter = this->hashMap->begin(); iter != this->hashMap->end(); ++iter) {
		delete iter->second;
	}
	delete this->hashMap;
	while (0 != this->children->size()) {
		delete this->children->at(this->children->size() - 1);
		this->children->pop_back();
	}
	delete this->children;
}

int Node::addItem(Item *item) {
	this->hashMap->emplace(item->name, item);
	return this->hashMap->size();
}

int Node::addChild(Node* child) {
	this->children->push_back(child);
	return this->children->size();
}

Item* Node::getItem(std::string name) {
	return this->hashMap->at(name);
}

Node* Node::getNextChild() {
	if (this->cursor >= this->children->size()) {
		return NULL;
	}
	return this->children->at(this->cursor++);
}

// Tree ============================================================

Item* Tree::getItemGlobal(std::string name) {
	if (NULL == this->current) {
		return NULL;
	}
	else {
		Node* pointer = this->current;
		while (NULL == pointer->getItem(name)) {
			if (NULL != pointer->parent) {
				pointer = pointer->parent;
			}
			else {
				break;
			}
		}
		return pointer->getItem(name);
	}
}

Tree::Tree() {
	this->root = new Node(NULL);
	this->current = this->root;
	this->currentType = TYPE_INT_IST;
}

Tree::~Tree() {
	delete this->root;
}

int Tree::pushScope(int creator) {
	if (NULL == this->current) {
		return -1;
	}
	if (creator) {
		this->current->addChild(new Node(this->current));
	}
	this->current = this->current->getNextChild();
	return 1;
}

int Tree::popScope() {
	if (NULL != this->current) {
		this->current->cursor = 0;
		if (NULL != this->current->parent) {
			this->current = this->current->parent;
			return 1;
		}
		return 0;
	}
	return -1;
}

int Tree::addWord(std::string name) {
	if (NULL == this->current) {
		return -1;
	}
	else {
		Item* item = new Item(name, this->currentType);
		this->current->addItem(item);
		return (int)item;
	}
}

int Tree::searchWord(std::string name) {
	if (NULL == this->current) {
		return -1;
	}
	else {
		return NULL == this->current->getItem(name);
	}
}

int Tree::searchWordGlobal(std::string name) {
	if (NULL == this->current) {
		return -1;
	}
	else {
		Node* pointer = this->current;
		while (NULL == pointer->getItem(name)) {
			if (NULL != pointer->parent) {
				pointer = pointer->parent;
			}
			else {
				break;
			}
		}
		return NULL == pointer->getItem(name);
	}
}

int Tree::searchWordInFunction(std::string name) {
	if (NULL == this->current) {
		return -1;
	}
	else {
		if (NULL == this->current->getItem(name)) {
			if (NULL == this->root->getItem(name)) {
				return 0;
			}
		}
		return 1;
	}
}

int Tree::setType(std::string name, int type) {
	return this->getItemGlobal(name)->modifyItemType(type);
}

int Tree::setStore(std::string name, int store, int position) {
	return this->getItemGlobal(name)->modifyItemStore(store, position);
}

int Tree::setTypeFunction(std::string name, int type) {
	Item* item = NULL;
	if (NULL == this->current) {
		return -1;
	}
	else {
		item = this->current->getItem(name);
		if (NULL == item) {
			item = this->root->getItem(name);
			if (NULL == item) {
				return 0;
			}
		}
		item->modifyItemType(type);
		return 1;
	}
}

int Tree::setStoreFunction(std::string name, int store, int position) {
	Item* item = NULL;
	if (NULL == this->current) {
		return -1;
	}
	else {
		item = this->current->getItem(name);
		if (NULL == item) {
			item = this->root->getItem(name);
			if (NULL == item) {
				return 0;
			}
		}
		item->modifyItemStore(store, position);
		return 1;
	}
}

int Tree::setCurrentType(int type) {
	this->currentType = type;
	return this->currentType;
}

int Tree::restart() {
	this->current = this->root;
	this->root->cursor = 0;
	return 1;
}