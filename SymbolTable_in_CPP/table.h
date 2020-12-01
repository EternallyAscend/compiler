//
// Created by MagicBook on 2020/11/15.
//

#ifndef TABLE_H
#define TABLE_H

int launchTable();

int stopTable();

int pushScope(int creator);

int popScope();

int addWord(char* name);

int searchWord(char* name);

int searchWordGlobal(char* name);

int setType(char* name, int type);

int setStore(char* name, int store, int position);

int setCurrentType(int type);

int setTypeFunction(char* name, int type);

int setStoreFunction(char* name, int store, int position);

int restartTable();

#endif // TABLE_H