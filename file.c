//
// Created by MagicBook on 2020/11/30.
//

#include "file.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>


int lex = 0;
int yacc = 0;
int report = 0;
int output = 0;

FILE* lexFile = NULL;
FILE* yaccFile = NULL;
FILE* reportFile = NULL;
FILE* outputCode = NULL;

char* getFileName(int time, const char* tail) {
    char* result = (char*)malloc(sizeof(char) * 32);
    sprintf(result, "%d%s", time, tail);
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

FILE* generateREPORT() {
    if (NULL == reportFile) {
        report = (int)time(NULL);
        if (0 > report) {
            report = -report;
        }
        char* reportName = getFileName(report, "-rep.txt");
        reportFile = fopen(reportName, "a+");
        free(reportName);
        return reportFile;
    }
    else {
        return reportFile;
    }
}

FILE* generateCODE() {
    if (NULL == outputCode) {
        output = (int)time(NULL);
        if (0 > output) {
            output = -output;
        }
        char* outputName = getFileName(output, "-code.txt");
        outputCode = fopen(outputName, "a+");
        free(outputName);
        return outputCode;
    }
    else {
        return outputCode;
    }
}

void appendLEX(char* content) {
    fputs(content, generateLEX());
}

void appendYACC(char* content) {
    fputs(content, generateYACC());
}

void appendREPORT(char* content) {
    fputs(content, generateREPORT());
}

void appendCode(char* content) {
    fputs(content, generateCODE());
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

void closeREPORT() {
    if (NULL != reportFile) {
        fclose(reportFile);
    }
}

void closeCODE() {
    if (NULL != outputCode) {
        fclose(outputCode);
    }
}
