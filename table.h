//
// Created by MagicBook on 2020/11/15.
//

#ifndef TABLE_H
#define TABLE_H

struct Word {
	const char* name;
	int type;
	int store;
	int position;
	int symbolPosition;
};

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
	int launchTable();

	int stopTable();

	int pushScope(int creator);

	int popScope();

	int addWord(const char* name);

	int searchWord(const char* name);

	int searchWordGlobal(const char* name);

	int setType(char* name, int type);

	int setStore(char* name, int store, int position);

	int setCurrentType(int type);

	int setTypeFunction(char* name, int type);

	int setStoreFunction(char* name, int store, int position);

	int restartTable();

	struct Word* getWordInfo(const char* name);

	struct Word* getWordInfoFunction(const char* name);

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // TABLE_H
