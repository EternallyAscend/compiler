//
// Created by MagicBook on 2020/11/30.
//

#include "file.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>


int lex = 0;
int yacc = 0;

FILE* lexFile = NULL;
FILE* yaccFile = NULL;

char* getFileName(int time, char* tail) {
    char* result = (char*)malloc(sizeof(char) * 32);
    strcpy(result, "../");
    sprintf(result, "%d", time);
    strcat(result, tail);
    return result;
}

FILE* generateLEX() {
    if (NULL == lexFile) {
        lex = (int)time(NULL);
        if (0 > lex) {
            lex = -lex;
        }
        char* lexName = getFileName(lex, "-lex.txt");
	    lexFile = fopen(lexName, "a+");
        free(lexName);
        return lexFile;
    }
    else {
        return lexFile;
    }
}

FILE* generateYACC() {
    if (NULL == yaccFile) {
        yacc = (int)time(NULL);
        if (0 > yacc) {
            yacc = -yacc;
        }
        char* yaccName = getFileName(yacc, "-yacc.txt");
	    yaccFile = fopen(yaccName, "a+");
	    free(yaccName);
        return yaccFile;
    }
    else {
        return yaccFile;
    }
}

void appendLEX(char* content) {
    fputs(content, generateLEX());
}

void appendYACC(char* content) {
    fputs(content, generateYACC());
}

void closeLEX() {
    if (NULL != lexFile) {
        fclose(lexFile);
    }
}

void closeYACC() {
    if (NULL != yaccFile) {
        fclose(yaccFile);
    }
}

