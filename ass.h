#ifndef TABLE_FILE_H
#define TABLE_FILE_H

#endif //TABLE_FILE_H

#include <stdio.h>

void start(char*** varyCode, int rowNum);

void end();

void assAdd(char* num1, char* num2, char* i);

void assMulti(char* num1, char* num2, char* i);

void assSub(char* num1, char* num2, char* i);

void assDiv(char* num1, char* num2, char* i);

void assRemainder(char* num1, char* num2, char* i);

void assPow(char* num1, char* num2, char* i);

void assAssgin(char* num1, char* num2, char* i);

void equalOrNot(char* num1, char* num2, char* i);

void notEqual(char* num1, char* num2, char* i);

void assLower(char* num1, char* num2, char* i);

void assLowerEqual(char* num1, char* num2, char* i); 

void assGreater(char* num1, char* num2, char* i); 

void assGreaterEqual(char* num1, char* num2, char* i);

void assNot(char* num1, char* i);

void Input(char* num1, char* i);

void Output(char* num1, char* i);

void assGetAddress(char *num1, char *i);

void assFind(char *num1, char *num2, char *i);

void assOffset(char *num1, char *num2, char *i);

void assJump(char *num1, char *num2, char *i);

int giveRow();

void saveVary(char*** threeCode, int i, char*** varyCode);

void readThree(char*** threeCode, char* i, char*** varyCode, int rowNum);