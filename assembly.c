#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"
#include "ass.h"
int lockOrNot = 0;
int addCount = 0;
int multiCount = 0;
int cmpEqualCount = 0;
int remCount = 0;
int cmpNotCount = 0;
int cmpGreaterCount = 0;
int cmpLowerCount = 0;
int cmpLowerEqualCount = 0;

char* mov = "MOV";
char* add = "ADD";
char* cmp = "CMP";
char* idiv ="IDIV";
char* jnb = "JNB";

char* ax = "eax";
char* bx = "ebx";
char* cx = "ecx";
char* zf = "zf";
char* ah = "ah";
char* cf = "cf";

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

char* assRemainder(int num1, int num2) {
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot == 1;
    char* count;
    char* firMove;
    char* secMove;
    char* storageResult;
    char *result;
    sprintf(count, "getRemainCount%d", remCount);
    sprintf(firMove, "%s %s, %d", mov, ax, num1);
    sprintf(secMove, "%s %s, %d", mov, bx, num2);
    sprintf(storageResult, "%s %s", idiv, bx);
    sprintf(result, "%s [%s], %s", mov, count, ah);
    remCount++;
    lockOrNot = 0;
    return count;
}

char* notEqual(int num1, int num2) {
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    char* count;
    char* firMove;
    char* compare;
    char* storageResult;
    char* result;
    sprintf(count, "cmpNotCount%d", cmpNotCount);
    sprintf(firMove, "%s %s, %d", mov, ax, num1);
    sprintf(firMove, "%s %s, %d", cmp, ax, num2);
    sprintf(result, "%s [%s], %s", mov, count, zf);
    cmpNotCount++;
    lockOrNot = 0;
    return count;
}

char* assLower(int num1, int num2) {
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    char* count;
    char* firMove;
    char* compare;
    char* storageResult;
    char* result;
    sprintf(count, "cmpLowerCount%d",  cmpLowerCount);
    sprintf(firMove, "%s %s, %d", mov, ax, num1);
    sprintf(firMove, "%s %s, %d", cmp, ax, num2);
    sprintf(result, "%s [%s], %s", mov, count, cf);
    cmpLowerCount++;
    lockOrNot = 0;
    return count;
}

char* assLowerEqual(int num1, int num2, char* nextStep) {
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    char* count;
    char* firMove;
    char* secMove;
    char* triMove;
    char* compare;
    char* storageResult;
    char* result;
    sprintf(count, "cmpLowerCount%d",  cmpLowerCount);
    sprintf(firMove, "%s %s, %d", mov, ax, num1);
    sprintf(secMove, "%s %s, %d", mov, bx, num2);
    sprintf(triMove, "%s %s, %s", mov, cx, nextStep);
    sprintf(storageResult, "%s %s, %s", cmp, ax, bx);
    sprintf(result, "%s [%s]", jnb, cx);
    cmpLowerCount++;
    lockOrNot = 0;
    return count;
}