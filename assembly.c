#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"

int lockOrNot = 0;
int addCount = 0;
int multiCount = 0;
int cmpEqualCount = 0;
int getRemainCount = 0;

char* mov = "mov";
char* add = "add";
char* cmp = "cmp";
char* idiv ="idiv";

char* ax = "eax";
char* bx = "ebx";
char* cx = "ecx";
char* zf = "zf";
char* ah = "ah";

void start(){
                                                                                              
}

void end(){
    
}

char* assAdd(char* num1, char* num2) {
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    char* count;
    char* firMove;
    char* secMove;
    char* firAdd;
    char* storageResult;
    sprintf(count, "addCount%d", addCount);
    sprintf(firMove, "%s %s, %s", mov, ax, num1);//put num1 to ax
    sprintf(secMove, "%s %s, %s", mov, bx, num2);//put num2 to bx
    sprintf(firAdd, "%s %s, %s", add, ax, bx);//ax = ax + bx
    sprintf(storageResult, "%s [%s], %s", mov , count, ax);//put ax to stroge
    addCount++;
    lockOrNot = 0;
    return count;
}

char* assMulti(int num1, int num2) {
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    char* count;
    char* firMove;
    char* secMove;
    char* thiMove;
    char* loop;
    char* storageResult;
    sprintf(count, "multiCount%d", multiCount);
    sprintf(firMove, "%s %s, %d", mov, ax, num1);//put num1 to ax
    sprintf(secMove, "%s %s, %d", mov, bx, num2);
    sprintf(thiMove, "%s %s, %d", mov, cx, num2);//put num2 to bx
    sprintf(loop, "m%d: %s %s, %s\n  loop m%d", multiCount, add, ax, bx, multiCount);
    sprintf(storageResult, "  %s [%s], %s", mov, count, ax);//put ax to stroge
    multiCount++;
    lockOrNot = 0;
    return count;
}

char* equalOrNot(int num1, int num2) {
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    char* count;
    char* firMove;
    char* compare;
    char* storageResult;
    char* result;
    sprintf(count, "cmpEqualCount%d", cmpEqualCount);
    sprintf(firMove, "%s %s, %d", mov, ax, num1);
    sprintf(firMove, "%s %s, %d", cmp, ax, num2);
    sprintf(result, "%s [%s], %s", mov, count, zf);
    cmpEqualCount++;
    lockOrNot = 0;
    return count;
}

char* getRemainder(int num1, int num2) {
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot == 1;
    char* count;
    char* firMove;
    char* secMove;
    char* storageResult;
    char *result;
    sprintf(count, "getRemainCount%d", getRemainCount);
    sprintf(firMove, "%s %s, %d", mov, ax, num1);
    sprintf(secMove, "%s %s, %d", mov, bx, num2);
    sprintf(storageResult, "%s %s", idiv, bx);
    sprintf(result, "%s [%S], %s", mov, count, ah);
    getRemainCount++;
    lockOrNot = 0;
    return count;
}