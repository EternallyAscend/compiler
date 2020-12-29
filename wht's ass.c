#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"
#include "ass.h"

int lockOrNot = 0;

char mov[] = "MOV";
char add[] = "ADD";
char sub[] = "SUB";
char imul[] = "IMUL";
char cmp[] = "CMP";
char idiv[] ="IDIV";

char ax[] = "eax";
char bx[] = "ebx";
char cx[] = "ecx";
char zf[] = "zf";
char al[] = "al";
char cf[] = "cf";

void assSub(char* num1, char* num2, char* i) {
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    char firMove[30];
    char secMove[30];
    char firSub[30];
    char storageResult[30];
    if(num1[0] == '?')
    {
        sprintf(firMove, "%s %s, [%s]", mov, ax, num1);
    }
    else if(num1[0] == '$')
    {
        sprintf(firMove, "%s %s, [%s]", mov, ax, num1);
    }
    else{
        sprintf(firMove, "%s %s, %s", mov, ax, num1);
    }
    if(num2[0] == '?')
    {
        sprintf(secMove, "%s %s, [%s]", mov, bx, num2);
    }
    else if(num2[0] == '$')
    {
        sprintf(secMove, "%s %s, [%s]", mov, bx, num2);
    }
    else{
        sprintf(secMove, "%s %s, %s", mov, bx, num2);
    }
    sprintf(firSub, "%s %s, %s", sub, ax, bx);//ax = ax + bx
    sprintf(storageResult, "%s [?%s], %s", mov , i, ax);//put ax to stroge
    FILE* f = fopen("ass.asm", 'a+');
    fprint(f, "%s\n", firMove);
    fprint(f, "%s\n", secMove);
    fprint(f, "%s\n", firSub);
    fprint(f, "%s\n", storageResult);
    lockOrNot = 0;
}

void assMulti(char* num1, char* num2, char* i) {
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    char firMove[30];
    char secMove[30];
    char firMulti[30];
    char storageResult[30];
    if(num1[0] == '?')
    {
        sprintf(firMove, "%s %s, [%s]", mov, ax, num1);
    }
    else if(num1[0] == '$')
    {
        sprintf(firMove, "%s %s, [%s]", mov, ax, num1);
    }
    else{
        sprintf(firMove, "%s %s, %s", mov, ax, num1);
    }
    if(num2[0] == '?')
    {
        sprintf(secMove, "%s %s, [%s]", mov, bx, num2);
    }
    else if(num2[0] == '$')
    {
        sprintf(secMove, "%s %s, [%s]", mov, bx, num2);
    }
    else{
        sprintf(secMove, "%s %s, %s", mov, bx, num2);
    }
    sprintf(firMulti, "%s %s, %s", imul, ax, bx);
    sprintf(storageResult, "%s [?%s], %s", mov, i, ax);//put ax to stroge
    FILE* f = fopen("ass.asm", 'a+');
    fprint(f, "%s\n", firMove);
    fprint(f, "%s\n", secMove);
    fprint(f, "%s\n", firMulti);
    fprint(f, "%s\n", storageResult);
    lockOrNot = 0;
}

void assDiv(char* num1, char* num2, char* i) {
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot == 1;
    char firMove[30];
    char secMove[30];
    char firDiv[30];
    char storageResult[30];
    if(num1[0] == '?')
    {
        sprintf(firMove, "%s %s, [%s]", mov, ax, num1);
    }
    else if(num1[0] == '$')
    {
        sprintf(firMove, "%s %s, [%s]", mov, ax, num1);
    }
    else{
        sprintf(firMove, "%s %s, %s", mov, ax, num1);
    }
    if(num2[0] == '?')
    {
        sprintf(secMove, "%s %s, [%s]", mov, bx, num2);
    }
    else if(num2[0] == '$')
    {
        sprintf(secMove, "%s %s, [%s]", mov, bx, num2);
    }
    else{
        sprintf(secMove, "%s %s, %s", mov, bx, num2);
    }
    sprintf(firDiv, "%s %s", idiv, bx);
    sprintf(storageResult, "%s [?%s], %s", mov, i, al);
    FILE* f = fopen("ass.asm", 'a+');
    fprint(f, "%s\n", firMove);
    fprint(f, "%s\n", secMove);
    fprint(f, "%s\n", firDiv);
    fprint(f, "%s\n", storageResult);
    lockOrNot = 0;
}

void assPow(char* num1, char* num2, char* i) {
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    char firMove[30];
    char secMove[30];
    char thiMove[30];
    char firSub[30];
    char loop[30];
    char storageResult[30];
    if(num1[0] == '?')
    {
        sprintf(firMove, "%s %s, [%s]", mov, ax, num1);
        sprintf(secMove, "%s %s, [%s]", mov, bx, num1);
    }
    else if(num1[0] == '$')
    {
        sprintf(firMove, "%s %s, [%s]", mov, ax, num1);
        sprintf(secMove, "%s %s, [%s]", mov, bx, num1);
    }
    else{
        sprintf(firMove, "%s %s, %s", mov, ax, num1);
        sprintf(secMove, "%s %S, %s", mov, bx, num1)
    }
    if(num2[0] == '?')
    {
        sprintf(thiMove, "%s %s, [%s]", mov, cx, num2);
    }
    else if(num2[0] == '$')
    {
        sprintf(thiMove, "%s %s, [%s]", mov, cx, num2);
    }
    else{
        sprintf(thiMove, "%s %s, %s", mov, cx, num2);
    }
    sprintf(firMove, "%s %s, [%s]", mov, ax, num1);//put num1 to ax
    sprintf(secMove, "%s %s, [%s]", mov, bx, num1);
    sprintf(thiMove, "%s %s, [%s]", mov, cx, num2);
    sprintf(firSub, "%s %s, %s", sub, cx, '1');
    sprintf(loop, "m%d: %s %s, %s\n  loop m%d", cx, imul, ax, bx, cx);
    sprintf(storageResult, "  %s [%s], %s", mov, i, ax);//put ax to stroge
    FILE* f = fopen("ass.asm", 'a+');
    fprint(f, "%s\n", firMove);
    fprint(f, "%s\n", secMove);
    fprint(f, "%s\n", thiMove);
    fprint(f, "%s\n", firSub);
    fprint(f, "%s\n", loop);
    fprint(f, "%s\n", storageResult);
    lockOrNot = 0;
}

void assAssgin(char* num1, char* num2,char* i) {
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    char firMove[30];
    char secMove[30];
    char firAssign[30];
    char storageResult[30];
    if(num1[0] == '?')
    {
        sprintf(firMove, "%s %s, [%s]", mov, ax, num1);
    }
    else if(num1[0] == '$')
    {
        sprintf(firMove, "%s %s, [%s]", mov, ax, num1);
    }
    else{
        sprintf(firMove, "%s %s, %s", mov, ax, num1);
    }
    if(num2[0] == '?')
    {
        sprintf(secMove, "%s %s, [%s]", mov, bx, num2);
    }
    else if(num2[0] == '$')
    {
        sprintf(firMove, "%s %s, [%s]", mov, ax, num1);
    }
    else{
        sprintf(secMove, "%s %s, %s", mov, bx, num2);
    }
    sprintf(firAssign, "%s %s, %s", mov, ax, bx);
    sprintf(storageResult, "%s [%s], %s", mov, i, ax);
    FILE* f = fopen("ass.asm", 'a+');
    fprint(f, "%s\n", firMove);
    fprint(f, "%s\n", secMove);
    fprint(f, "%s\n", firAssign);
    fprint(f, "%s\n", storageResult);
    lockOrNot = 0;
}
