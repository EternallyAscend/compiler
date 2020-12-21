//
// Created by MagicBook on 2020/11/15.
//

#ifndef TABLE_H
#define TABLE_H

struct Word {
	const char* name;
	int type;
	int store;
	// int position;
	char* position;
	int symbolPosition;
};

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
	int launchTable();

	int stopTable();

	int pushScope(const int creator);

	int popScope();

	int addWord(const char* name);

	int searchWord(const char* name);

	int searchWordGlobal(const char* name);

	int setType(const char* name, const int type);

	// int setStore(const char* name, const int store, const int position);
	int setStore(const char* name, const int store, const char* position);

	int setCurrentType(const int type);

	int setTypeFunction(const char* name, const int type);

	// int setStoreFunction(const char* name, const int store, const int position);
	int setStoreFunction(const char* name, const int store, const char* position);

// 	int pushStruct(const char* name);
// 
// 	int popStruct();
// 
// 	int searchStruct(const char* name);

	int restartTable();

	struct Word* getWordInfo(const char* name);

	struct Word* getWordInfoFunction(const char* name);

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // TABLE_H
