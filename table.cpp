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

int pushScope(const int creator) {
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

int addWord(const char* name) {
	if (NULL == symbolTable) {
		return 0;
	}
	else {
		return symbolTable->addWord(name);
	}
}

int searchWord(const char* name) {
	if (NULL == symbolTable) {
		return 0;
	}
	else {
		return symbolTable->searchWord(name);
	}
}

int searchWordGlobal(const char* name) {
	if (NULL == symbolTable) {
		return 0;
	}
	else {
		return symbolTable->searchWordGlobal(name);
	}
}

int setType(const char* name, const int type) {
	if (NULL == symbolTable) {
		return 0;
	}
	else {
		return symbolTable->setType(name, type);
	}
}

int setStore(const char* name, const int store, char* position) {
	if (NULL == symbolTable) {
		return 0;
	}
	else {
		return symbolTable->setStore(name, store, position);
	}
}

int setCurrentType(const int type) {
	if (NULL == symbolTable) {
		return 0;
	}
	else {
		return symbolTable->setCurrentType(type);
	}
}

int setTypeFunction(const char* name, const int type) {
	if (NULL == symbolTable) {
		return 0;
	}
	else {
		return symbolTable->setTypeFunction(name, type);
	}
}

// int setStoreFunction(const char* name, const int store, const int position) {
int setStoreFunction(const char* name, const int store, char* position) {
	if (NULL == symbolTable) {
		return 0;
	}
	else {
		return symbolTable->setStoreFunction(name, store, position);
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

struct Word* getWordInfo(const char* name) {
	if (NULL == symbolTable) {
		printf("HELP! NULL symbolTable.\n");
		return NULL;
	}
	else {
		return symbolTable->getWordGlobal(name);
	}
}

struct Word* getWordInfoFunction(const char* name) {
	if (NULL == symbolTable) {
		return NULL;
	}
	else {
		return symbolTable->getWordFunction(name);
	}
}
