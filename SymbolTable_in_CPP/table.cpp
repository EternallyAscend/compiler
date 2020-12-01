//
// Created by MagicBook on 2020/11/15.
//

#include <stdio.h>
#include "table.h"
#include "tree.h"

Tree* symbolTable = NULL;

int launchTable() {
	if (NULL == symbolTable) {
		symbolTable = new Tree();
		return 1;
	}
	else {
		return 2;
	}
}

int stopTable() {
	if (NULL == symbolTable) {
		return 0;
	}
	else {
		delete symbolTable;
		symbolTable = NULL;
		return 1;
	}
}

int pushScope(int creator) {
	if (NULL == symbolTable) {
		return 0;
	}
	else {
		return symbolTable->pushScope(creator);
	}
}

int popScope() {
	if (NULL == symbolTable) {
		return 0;
	}
	else {
		return symbolTable->popScope();
	}
}

int addWord(char* name) {
	if (NULL == symbolTable) {
		return 0;
	}
	else {
		return symbolTable->addWord(name);
	}
}

int searchWord(char* name) {
	if (NULL == symbolTable) {
		return 0;
	}
	else {
		return symbolTable->searchWord(name);
	}
}

int searchWordGlobal(char* name) {
	if (NULL == symbolTable) {
		return 0;
	}
	else {
		return symbolTable->searchWordGlobal(name);
	}
}

int setType(char* name, int type) {
	if (NULL == symbolTable) {
		return 0;
	}
	else {
		return symbolTable->setType(name, type);
	}
}

int setStore(char* name, int store, int position) {
	if (NULL == symbolTable) {
		return 0;
	}
	else {
		return symbolTable->setStore(name, store, position);
	}
}

int setCurrentType(int type) {
	if (NULL == symbolTable) {
		return 0;
	}
	else {
		return symbolTable->setCurrentType(type);
	}
}

int setTypeFunction(char* name, int type) {
	if (NULL == symbolTable) {
		return 0;
	}
	else {
		return symbolTable->setTypeFunction(name, type);
	}
}

int setStoreFunction(char* name, int store, int position) {
	if (NULL == symbolTable) {
		return 0;
	}
	else {
		return symbolTable->setStore(name, store, position);
	}
}

int restartTable() {
	if (NULL == symbolTable) {
		return 0;
	}
	else {
		return symbolTable->restart();
	}
}
