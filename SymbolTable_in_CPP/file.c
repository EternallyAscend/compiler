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
//    char* result = (char*)malloc(sizeof(char) * 18);
    printf("%d\n", time);
    sprintf(result, "%d", time);
//    result = "01";
    printf("%s\n", result);
    strcat(result, tail);
    printf("%s\n", result);
    return result;
}

FILE* generateLEX() {
    if (NULL == lexFile) {
        lex = (int)time(NULL);
        if (0 > lex) {
            lex = -lex;
        }
        char* lexName = getFileName(lex, "-lex.txt");
        int err = fopen_s(&lexFile, lexName, "a+");
        free(lexName);
//        printf("%s\n", getFileName(lex, "-lex.txt"));
//        int err = fopen_s(&lexFile, getFileName(lex, "-lex.txt"), "a+");
        if (0 != err) {
            printf("%d\n", err);
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
        char* yaccName = getFileName(yacc, "-yacc.txt");
        int err = fopen_s(&yaccFile, yaccName, "a+");
        free(yaccName);
//        printf("%s\n", getFileName(yacc, "-yacc.txt"));
//        int err = fopen_s(&yaccFile, getFileName(yacc, "-yacc.txt"), "a+");
        if (0 != err) {
            printf("%d\n", err);
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
    printf("%s\n", content);
    fputs(content, generateLEX());
}

void appendYACC(char* content) {
    printf("%s\n", content);
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

