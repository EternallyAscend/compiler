#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"
#include "ass.h"

int lockOrNot = 0;
int subCount = 0;

char* mov = "MOV";
char* add = "ADD";
char* sub = "SUB";
char* cmp = "CMP";
char* idiv ="IDIV";
char* jnb = "JNB";

char* ax = "eax";
char* bx = "ebx";
char* cx = "ecx";
char* zf = "zf";
char* ah = "ah";
char* cf = "cf";

char* assSub(char* num1, char* num2) {
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    char* count;
    char* firMove;
    char* secMove;
    char* firSub;
    char* storageResult;
    sprintf(count, "subCount%d", subCount);
    sprintf(firMove, "%s %s, %s", mov, ax, num1);//put num1 to ax
    sprintf(secMove, "%s %s, %s", mov, bx, num2);//put num2 to bx
    sprintf(firSub, "%s %s, %s", sub, ax, bx);//ax = ax + bx
    sprintf(storageResult, "%s [%s], %s", mov , count, ax);//put ax to stroge
    subCount++;
    lockOrNot = 0;
    return count;
}

char* assPow(char* num1, char* num2) {
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    
    
    lockOrNot = 0;
    return count;
}