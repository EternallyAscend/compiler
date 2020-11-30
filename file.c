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
    char* result;
    itoa(time, result, 10);
    strcat(result, tail);
    return result;
}

FILE* generateLEX() {
    if (NULL == lexFile) {
        lex = (int)time(NULL);
        if (0 > lex) {
            lex = -lex;
        }
        int err = fopen_s(&lexFile, getFileName(lex, "-lex.txt"), "a+");
        if (0 != err) {
            exit(-1);
        }
//        lexFile = fopen(getFileName(lex, "lex.txt"), "w");
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
        int err = fopen_s(&yaccFile, getFileName(yacc, "-yacc.txt"), "a+");
        if (0 != err) {
            exit(-1);
        }
//        yaccFile = fopen(getFileName(yacc, "yacc.txt"), "w");
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

void closeLex() {
    if (NULL != lexFile) {
        fclose(lexFile);
    }
}

void closeYacc() {
    if (NULL != yaccFile) {
        fclose(yaccFile);
    }
}

