//
// Created by MagicBook on 2020/11/30.
//

#ifndef TABLE_FILE_H
#define TABLE_FILE_H

#endif //TABLE_FILE_H

#include <stdio.h>

char* getFileName(int time, const char* tail);

FILE* generateLEX();

FILE* generateYACC();

FILE* generateREPORT();

void appendLEX(char* content);

void appendYACC(char* content);

void appendREPORT(char* content);

void closeLEX();

void closeYACC();

void closeREPORT();
