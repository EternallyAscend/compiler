#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"
#include "ass.h"

int lockOrNot = 0;
int multiCount = 0;
int divCount = 0;
int powCount = 0;
int cmpGreaterCount = 0;
int assignCount = 0;

char mov[] = "MOV";
char* add = "ADD";
char sub[] = "SUB";
char* imul = "IMUL";
char* cmp = "CMP";
char* idiv ="IDIV";
char* jnb = "JNB";

char ax[] = "eax";
char bx[] = "ebx";
char* cx = "ecx";
char* zf = "zf";
char* al = "al";
char* cf = "cf";

void assSub(char* num1, char* num2, char* i) {
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    char firMove[30];
    char secMove[30];
    char firSub[30];
    char storageResult[30];
    if(num1[0] == '#')
    {
        sprintf(firMove, "%s %s, [%s]", mov, ax, num1);
    }
    else{
        sprintf(firMove, "%s %s, %s", mov, ax, num1);
    }
    if(num2[0] == '#')
    {
        sprintf(secMove, "%s %s, [%s]", mov, bx, num2);
    }
    else{
        sprintf(secMove, "%s %s, %s", mov, bx, num2);
    }
    sprintf(firSub, "%s %s, %s", sub, ax, bx);//ax = ax + bx
    sprintf(storageResult, "%s [#%s], %s", mov , i, ax);//put ax to stroge
    FILE* f = fopen("ass.asm", 'a+');
    fprint(f, "%s\n", firMove);
    fprint(f, "%s\n", secMove);
    fprint(f, "%s\n", firSub);
    fprint(f, "%s\n", storageResult);
    lockOrNot = 0;
}

char* assMulti(char* num1, char* num2) {
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    char* count;
    char* firMove;
    char* secMove;
    char* firMulti;
    char* storageResult;
    sprintf(count, "multiCount%d", multiCount);
    sprintf(firMove, "%s %s, [%s]", mov, ax, num1);//put num1 to ax
    sprintf(secMove, "%s %s, [%s]", mov, bx, num2);
    sprintf(firMulti, "%s %s, %s", imul, ax, bx);
    sprintf(storageResult, "%s [%s], %s", mov, count, ax);//put ax to stroge
    multiCount++;
    lockOrNot = 0;
    return count;
}

char* assDiv(char* num1, char* num2) {
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot == 1;
    char* count;
    char* firMove;
    char* secMove;
    char* firDiv;
    char* storageResult;
    sprintf(count, "divCount%d", divCount);
    sprintf(firMove, "%s %s, [%s]", mov, ax, num1);
    sprintf(secMove, "%s %s, [%s]", mov, bx, num2);
    sprintf(firDiv, "%s %s", idiv, bx);
    sprintf(storageResult, "%s [%s], %s", mov, count, al);
    divCount++;
    lockOrNot = 0;
    return count;
}

char* assPow(char* num1, char* num2) {
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    char* count;
    char* firMove;
    char* secMove;
    char* thiMove;
    char* firSub;
    char* loop;
    char* storageResult;
    sprintf(count, "powCount%d", powCount);
    sprintf(firMove, "%s %s, [%s]", mov, ax, num1);//put num1 to ax
    sprintf(secMove, "%s %s, [%s]", mov, bx, num1);
    sprintf(thiMove, "%s %s, [%s]", mov, cx, num2);
    sprintf(firSub, "%s %s, %s", sub, cx, '1');
    sprintf(loop, "m%d: %s %s, %s\n  loop m%d", powCount, imul, ax, bx, powCount);
    sprintf(storageResult, "  %s [%s], %s", mov, count, ax);//put ax to stroge
    powCount++;
    lockOrNot = 0;
    return count;
}

char* assAssgin(char* num1, char* num2) {
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    char* count;
    char* firMove;
    char* firAssign;
    char* storageResult;
    sprintf(count, "assignCount%d", assignCount);
    sprintf(firMove, "%s %s, [%s]", mov, ax, num1);
    sprintf(firAssign, "%s %s, [%s]", mov, ax, num2);
    sprintf(storageResult, "%s [%s], %s", mov, count, ax);
    assignCount++;
    lockOrNot = 0;
    return count;
}
char* assGreater(char* num1, char* num2) {

}

char* assGreaterEqual(char* num1, char* num2);