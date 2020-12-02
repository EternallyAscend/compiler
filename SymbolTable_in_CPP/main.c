//
// Created by MagicBook on 2020/12/01.
//

#include <stdio.h>
#include <stdlib.h>

#include "table.h"

int main(void) {
	launchTable();
	printf("0x%d\n", addWord("Global"));
	pushScope(1);
	printf("0x%d\n", addWord("Global"));
	struct Word* word = getWordInfoFunction("Global");
	printf("%s %d %d %d 0x%d\n", word->name, word->type, word->store, word->position, word->symbolPosition);
	free(word);
	pushScope(1);
	printf("0x%d\n", addWord("Tom"));
	printf("%d\n", searchWord("Tom"));
	printf("%d\n", searchWord("tom"));
	word = getWordInfoFunction("Global");
	printf("%s %d %d %d 0x%d\n", word->name, word->type, word->store, word->position, word->symbolPosition);
	free(word);
	setType("Tom", 5);
	setType("Global", 6);
	printf("%d\n", searchWord("Global"));
	printf("%d\n", searchWordGlobal("Global"));
	word = getWordInfoFunction("Global");
	printf("%s %d %d %d 0x%d\n", word->name, word->type, word->store, word->position, word->symbolPosition);
	free(word);
	printf("Scope: %d\n", popScope());
	printf("Scope: %d\n", popScope());
	restartTable();
	pushScope(0);
	printf("%d\n", searchWord("tom"));
	printf("%d\n", searchWord("Global"));
	printf("%d\n", searchWordGlobal("Global"));
	word = getWordInfo("Global");
	printf("%s %d %d %d 0x%d\n", word->name, word->type, word->store, word->position, word->symbolPosition);
	free(word);
	printf("After.\n");
	popScope();
	printf("%d\n", searchWord("Global"));
	printf("%d\n", searchWordGlobal("Global"));
	stopTable();
	return 0;
}