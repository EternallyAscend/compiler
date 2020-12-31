#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "file.h"
#include "ass.h"
int lockOrNot = 0;
char mov[] = "mov";
char add[] = "add";
char sub[] = "sub";
char imul[] = "imul";
char cmp[] = "cmp";
char idiv[] ="idiv";
char jnb[] = "jnb";
char jb[] = "jb";
char je[] = "je";
char jne[] = "jne";
char jna[] = "jna";
char ja[] = "ja";
char jg[] = "jg";
char jmp[] = "jmp";
char lea[] = "lea";
char in[] = "in";
char out[] = "out";
char sete[] =  "sete";
char setge[] = "setge";
char setg[] = "setg";
char setl[] = "setl";
char setle[] = "setle";
char setne[] = "setne";

char ax[] = "eax";
char bx[] = "ebx";
char cx[] = "ecx";
char zf[] = "zf";
char ah[] = "ah";
char al[] = "al";
char cf[] = "cf";
char sf[] = "sf";

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
    else if(num1[0] == '@')
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
    else if(num2[0] == '@')
    {
        sprintf(secMove, "%s %s, [%s]", mov, bx, num2);
    }
    else{
        sprintf(secMove, "%s %s, %s", mov, bx, num2);
    }
    sprintf(firSub, "%s %s, %s", sub, ax, bx);//ax = ax + bx
    sprintf(storageResult, "%s [?%s], %s", mov , i, ax);//put ax to stroge
    FILE* f = fopen("ass.asm", "a+");
    fprintf(f, "L%s:\n", i);
    fprintf(f, "%s\n", firMove);
    fprintf(f, "%s\n", secMove);
    fprintf(f, "%s\n", firSub);
    fprintf(f, "%s\n", storageResult);
    fclose(f);
    lockOrNot = 0;
}

void assAdd(char* num1, char* num2, char* i) {
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;

    char firMove[30];
    char secMove[30];
    char firAdd[30];
    char storageResult[30];
     if(num1[0] == '?')
    {
        sprintf(firMove, "%s %s, [%s]", mov, ax, num1);
    }
     else if(num1[0] == '@')
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
     else if(num2[0] == '@')
    {
        sprintf(secMove, "%s %s, [%s]", mov, bx, num2);
    }
    else{
        sprintf(secMove, "%s %s, %s", mov, bx, num2);
    }
    sprintf(firAdd, "%s %s, %s", add, ax, bx);//ax = ax + bx
    sprintf(storageResult, "%s [?%s], %s", mov, i, ax);//put ax to 
    FILE* f = fopen("ass.asm", "a+");
    fprintf(f, "L%s:\n", i);
    fprintf(f, "%s\n", firMove);
    fprintf(f, "%s\n", secMove);
    fprintf(f, "%s\n", firAdd);
    fprintf(f, "%s\n", storageResult);
    fclose(f);
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
    else if(num1[0] == '@')
    {
        sprintf(firMove, "%s %s, [%s]", mov, ax, num1);
        sprintf(secMove, "%s %s, [%s]", mov, bx, num1);
    }
    else{
        sprintf(firMove, "%s %s, %s", mov, ax, num1);
        sprintf(secMove, "%s %s, %s", mov, bx, num1);
    }
    
    if(num2[0] == '?')
    {
        sprintf(thiMove, "%s %s, [%s]", mov, cx, num2);
    }
    else if(num2[0] == '@')
    {
        sprintf(thiMove, "%s %s, [%s]", mov, cx, num2);
    }
    else{
        sprintf(thiMove, "%s %s, %s", mov, cx, num2);
    }
    sprintf(firSub, "%s %s, %s", sub, cx, "1");
    sprintf(loop, "m%s: %s %s, %s\nloop m%s", i, imul, ax, bx, i);
    sprintf(storageResult, "%s [?%s], %s", mov, i, ax);//put ax to stroge
    FILE* f = fopen("ass.asm", "a+");
    fprintf(f, "L%s:\n", i);
    fprintf(f, "%s\n", firMove);
    fprintf(f, "%s\n", secMove);
    fprintf(f, "%s\n", thiMove);
    fprintf(f, "%s\n", firSub);
    fprintf(f, "%s\n", loop);
    fprintf(f, "%s\n", storageResult);
    fclose(f);
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
    else if(num1[0] == '@')
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
    else if(num2[0] == '@')
    {
        sprintf(secMove, "%s %s, [%s]", mov, bx, num2);
    }
    else{
        sprintf(secMove, "%s %s, %s", mov, bx, num2);
    }
    sprintf(firMulti, "%s %s, %s", imul, ax, bx);
    sprintf(storageResult, "%s [?%s], %s", mov, i, ax);//put ax to stroge
    FILE* f = fopen("ass.asm", "a+");
    fprintf(f, "L%s:\n", i);
    fprintf(f, "%s\n", firMove);
    fprintf(f, "%s\n", secMove);
    fprintf(f, "%s\n", firMulti);
    fprintf(f, "%s\n", storageResult);
    fclose(f);
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
    else if(num1[0] == '@')
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
    else if(num2[0] == '@')
    {
        sprintf(secMove, "%s %s, [%s]", mov, bx, num2);
    }
    else{
        sprintf(secMove, "%s %s, %s", mov, bx, num2);
    }
    sprintf(firDiv, "%s %s", idiv, bx);
    sprintf(storageResult, "%s [?%s], %s", mov, i, al);
    FILE* f = fopen("ass.asm", "a+");
    fprintf(f, "L%s:\n", i);
    fprintf(f, "%s\n", firMove);
    fprintf(f, "%s\n", secMove);
    fprintf(f, "%s\n", firDiv);
    fprintf(f, "%s\n", storageResult);
    fclose(f);
    lockOrNot = 0;
}

void assRemainder(char* num1, char* num2, char *i) {
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot == 1;
    char firMove[30];
    char secMove[30];
    char storageResult[30];
    char result[30];
     if(num1[0] == '?')
    {
        sprintf(firMove, "%s %s, [%s]", mov, ax, num1);
    }
     else if(num1[0] == '@')
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
     else if(num2[0] == '@')
    {
        sprintf(secMove, "%s %s, [%s]", mov, bx, num2);
    }
    else{
        sprintf(secMove, "%s %s, %s", mov, bx, num2);
    }
    sprintf(result, "%s %s", idiv, bx);
    sprintf(storageResult, "%s [?%s], %s", mov, i, ah);
    FILE* f = fopen("ass.asm", "a+");
    fprintf(f, "L%s:\n", i);
    fprintf(f, "%s\n", firMove);
    fprintf(f, "%s\n", secMove);
    fprintf(f, "%s\n", result);
    fprintf(f, "%s\n", storageResult);
    fclose(f);
    lockOrNot = 0;
}

void assAssgin(char* num1, char* num2,char* i) {
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    char firMove[30];
    char firAssign[30];
    char storageResult[30];
    if(num2[0] == '?')
    {
        sprintf(firMove, "%s %s, [%s]", mov, ax, num2);
    }
    else if(num2[0] == '@')
    {
        sprintf(firMove, "%s %s, [%s]", mov, ax, num2);
    }
    else{
        sprintf(firMove, "%s %s, %s", mov, ax, num2);
    }
    if(num1[0] == '?')
    {
        sprintf(firAssign, "%s [%s], %s", mov, num1, ax);
    }
    else if(num1[0] == '@')
    {
        sprintf(firAssign, "%s [%s], %s", mov, num1, ax);
    }
    else if(num1[0] == '[')
    {
    	sprintf(firAssign, "%s %s, %s\n%s [%s], %s", mov, bx, num1, mov, bx, ax);
	}
    else{
        sprintf(firAssign, "%s %s, %s", mov, num1, ax);
    }
    sprintf(storageResult, "%s [?%s], %s", mov, i, ax);
    FILE* f = fopen("ass.asm", "a+");
    fprintf(f, "L%s:\n", i);
    fprintf(f, "%s\n", firMove);
    fprintf(f, "%s\n", firAssign);
    fprintf(f, "%s\n", storageResult);
    fclose(f);
    lockOrNot = 0;
}

void assNot(char* num1, char* i){
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    char firMove[30];
    char getNot[30];
    char getZf[30];
    char storageResult[30];
    if(num1[0] == '#')
    {
        sprintf(firMove, "%s %s, [%s]", mov, ax, num1);
    }
     else if(num1[0] == '@')
    {
        sprintf(firMove, "%s %s, [%s]", mov, ax, num1);
    }
    else{
        sprintf(firMove, "%s %s, %s", mov, ax, num1);
    }
    sprintf(getNot, "%s %s, 0", cmp, ax);
    sprintf(getZf, "%s %s", sete, al);
    sprintf(storageResult, "%s [?%s], %s", mov, i, al);
    FILE* f = fopen("ass.asm", "a+");
    fprintf(f, "L%s:\n", i);
    fprintf(f, "%s\n", firMove);
    fprintf(f, "%s\n", getNot);
    fprintf(f, "%s\n", getZf);
    fprintf(f, "%s\n", storageResult);
    fclose(f);
    lockOrNot = 0;
}

void notEqual(char* num1, char* num2, char* i) {
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    char firMove[30];
    char secMove[30];
    char compare[30];
    char storageResult[30];
    char result[30];
     if(num1[0] == '?')
    {
        sprintf(firMove, "%s %s, [%s]", mov, ax, num1);
    }
     else if(num1[0] == '@')
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
     else if(num2[0] == '@')
    {
        sprintf(secMove, "%s %s, [%s]", mov, bx, num2);
    }
    else{
        sprintf(secMove, "%s %s, %s", mov, bx, num2);
    }
    sprintf(compare, "%s %s, %s", cmp, ax, bx);
    sprintf(result, "%s %s", setne, al);
    sprintf(storageResult, "%s [?%s], %s", mov, i, al);
    FILE* f = fopen("ass.asm", "a+");
    fprintf(f, "L%s:\n", i);
    fprintf(f, "%s\n", firMove);
    fprintf(f, "%s\n", secMove);
    fprintf(f, "%s\n", compare);
    fprintf(f, "%s\n", result);
    fprintf(f, "%s\n", storageResult);
    fclose(f);
    lockOrNot = 0;
}

void equalOrNot(char* num1, char* num2, char* i) {
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    char firMove[30];
    char secMove[30];
    char compare[30];
    char getZf[30];
    char storageResult[30];
    char result[30];
    if(num1[0] == '?')
    {
        sprintf(firMove, "%s %s, [%s]", mov, ax, num1);
    }
     else if(num1[0] == '@')
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
     else if(num2[0] == '@')
    {
        sprintf(secMove, "%s %s, [%s]", mov, bx, num2);
    }
    else{
        sprintf(secMove, "%s %s, %s", mov, bx, num2);
    }
    sprintf(compare, "%s %s, %s", cmp, ax, bx);
    sprintf(getZf, "%s %s", sete, al);
    sprintf(storageResult, "%s [?%s], %s", mov, i, al);
    FILE* f = fopen("ass.asm", "a+");
    fprintf(f, "L%s:\n", i);
    fprintf(f, "%s\n", firMove);
    fprintf(f, "%s\n", secMove);
    fprintf(f, "%s\n", compare);
    fprintf(f, "%s\n", getZf);
    fprintf(f, "%s\n", storageResult);
    fclose(f);
    lockOrNot = 0;
}

void assLower(char* num1, char* num2, char* i) {
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    char firMove[30];
    char secMove[30];
    char compare[30];
    char storageResult[30];
    char result[30];
        if(num1[0] == '?')
    {
        sprintf(firMove, "%s %s, [%s]", mov, ax, num1);
    }
     else if(num1[0] == '@')
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
     else if(num2[0] == '@')
    {
        sprintf(secMove, "%s %s, [%s]", mov, bx, num2);
    }
    else{
        sprintf(secMove, "%s %s, %s", mov, bx, num2);
    }
    sprintf(compare, "%s %s, %s", cmp, ax, bx);
    sprintf(result, "%s %s", setl, al);
    sprintf(storageResult, "%s [?%s], %s", mov, i, al);
    FILE* f = fopen("ass.asm", "a+");
    fprintf(f, "L%s:\n", i);
    fprintf(f, "%s\n", firMove);
    fprintf(f, "%s\n", secMove);
    fprintf(f, "%s\n", compare);
    fprintf(f, "%s\n", result);
    fprintf(f, "%s\n", storageResult);
    fclose(f);
    lockOrNot = 0;
}

void assLowerEqual(char* num1, char* num2, char* i) {
   while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    char firMove[30];
    char secMove[30];
    char compare[30];
    char storageResult[30];
    char result[30];
        if(num1[0] == '?')
    {
        sprintf(firMove, "%s %s, [%s]", mov, ax, num1);
    }
     else if(num1[0] == '@')
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
     else if(num2[0] == '@')
    {
        sprintf(secMove, "%s %s, [%s]", mov, bx, num2);
    }
    else{
        sprintf(secMove, "%s %s, %s", mov, bx, num2);
    }
    sprintf(compare, "%s %s, %s", cmp, ax, bx);
    sprintf(result, "%s %s", setle, al);
    sprintf(storageResult, "%s [?%s], %s", mov, i, al);
    FILE* f = fopen("ass.asm", "a+");
    fprintf(f, "L%s:\n", i);
    fprintf(f, "%s\n", firMove);
    fprintf(f, "%s\n", secMove);
    fprintf(f, "%s\n", compare);
    fprintf(f, "%s\n", result);
    fprintf(f, "%s\n", storageResult);
    fclose(f);
    lockOrNot = 0;
}

void assGreater(char* num1, char* num2, char* i) {
   while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    char firMove[30];
    char secMove[30];
    char compare[30];
    char storageResult[30];
    char result[30];
        if(num1[0] == '?')
    {
        sprintf(firMove, "%s %s, [%s]", mov, ax, num1);
    }
     else if(num1[0] == '@')
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
     else if(num2[0] == '@')
    {
        sprintf(secMove, "%s %s, [%s]", mov, bx, num2);
    }
    else{
        sprintf(secMove, "%s %s, %s", mov, bx, num2);
    }
    sprintf(compare, "%s %s, %s", cmp, ax, bx);
    sprintf(result, "%s %s", setg, al);
    sprintf(storageResult, "%s [?%s], %s", mov, i, al);
    FILE* f = fopen("ass.asm", "a+");
    fprintf(f, "L%s:\n", i);
    fprintf(f, "%s\n", firMove);
    fprintf(f, "%s\n", secMove);
    fprintf(f, "%s\n", compare);
    fprintf(f, "%s\n", result);
    fprintf(f, "%s\n", storageResult);
    fclose(f);
    lockOrNot = 0;
}

void assGreaterEqual(char* num1, char* num2, char* i) {
     while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    char firMove[30];
    char secMove[30];
    char compare[30];
    char storageResult[30];
    char result[30];
        if(num1[0] == '?')
    {
        sprintf(firMove, "%s %s, [%s]", mov, ax, num1);
    }
     else if(num1[0] == '@')
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
     else if(num2[0] == '@')
    {
        sprintf(secMove, "%s %s, [%s]", mov, bx, num2);
    }
    else{
        sprintf(secMove, "%s %s, %s", mov, bx, num2);
    }
    sprintf(compare, "%s %s, %s", cmp, ax, bx);
    sprintf(result, "%s %s", setge, al);
    sprintf(storageResult, "%s [?%s], %s", mov, i, al);
    FILE* f = fopen("ass.asm", "a+");
    fprintf(f, "L%s:\n", i);
    fprintf(f, "%s\n", firMove);
    fprintf(f, "%s\n", secMove);
    fprintf(f, "%s\n", compare);
    fprintf(f, "%s\n", result);
    fprintf(f, "%s\n", storageResult);
    fclose(f);
    lockOrNot = 0;
}

void Input(char* num1, char* i) {
   while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    char firMove[30];
    char secMove[30];
    char getin[30];
        if(num1[0] == '?')
    {
        sprintf(firMove, "%s [%s], %s", mov, num1, ax);
    }
     else if(num1[0] == '@')
    {
        sprintf(firMove, "%s [%s], %s", mov, num1, ax);
    }
    else{
        sprintf(firMove, "%s %s, %s", mov, num1, ax);
    }
    sprintf(getin, "%s %s, 21H", in, ax);
    FILE* f = fopen("ass.asm", "a+");
    fprintf(f, "L%s:\n", i);
    fprintf(f, "%s\n", getin);
    fprintf(f, "%s\n", firMove);
    fclose(f);
    lockOrNot = 0;
}

void Output(char* num1, char* i) {
   while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    char firMove[30];
    char secMove[30];
    char getout[30];
        if(num1[0] == '?')
    {
        sprintf(firMove, "%s %s, [%s]", mov, ax, num1);
    }
     else if(num1[0] == '@')
    {
        sprintf(firMove, "%s %s, [%s]", mov, ax, num1);
    }
    else{
        sprintf(firMove, "%s %s, %s", mov, ax, num1);
    }
    sprintf(getout, "%s 378H, %s", out, ax);
    FILE* f = fopen("ass.asm", "a+");
    fprintf(f, "L%s:\n", i);
    fprintf(f, "%s\n", firMove);
    fprintf(f, "%s\n", getout);
    fclose(f);
    lockOrNot = 0;
}

void assOffset(char *num1, char *num2, char *i){
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    char getAddress[30];
    char thiMove[30];
    char firAdd[30];
    sprintf(getAddress, "%s %s, [%s]", lea, ax, num1);
    if(num2[0] == '?' || num2[0] == '@')
    {
        sprintf(firAdd, "%s %s, [%s]", add, ax, num2);
    }
    else{
        sprintf(firAdd, "%s %s, %s", add, ax, num2);
    }
    sprintf(thiMove, "%s [?%s], %s", mov, i, ax);
    FILE* f = fopen("ass.asm", "a+");
    fprintf(f, "L%s:\n", i);
    fprintf(f, "%s\n", getAddress);
    fprintf(f, "%s\n", firAdd);
    fprintf(f, "%s\n", thiMove);
    fclose(f);
    lockOrNot = 0;
}

void assFind(char *num1, char *i){
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    char firMove[30];
    char secMove[30];
    char thiMove[30];
    sprintf(firMove, "%s %s, [%s]", mov, bx, num1);
    sprintf(secMove, "%s %s, [%s]", mov, ax, bx);
    sprintf(thiMove, "%s [?%s], %s", mov, i, ax);
    FILE* f = fopen("ass.asm", "a+");
    fprintf(f, "L%s:\n", i);
    fprintf(f, "%s\n", firMove);
    fprintf(f, "%s\n", secMove);
    fprintf(f, "%s\n", thiMove);
    fclose(f);
    lockOrNot = 0;
}

void assGetAddress(char *num1, char *i){
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    char getAddress[30];
    char firMove[30];
    sprintf(getAddress, "%s %s, [%s]", lea, ax, num1);
    sprintf(firMove, "%s [?%s], %s", mov, i, ax);
    FILE* f = fopen("ass.asm", "a+");
    fprintf(f, "L%s:\n", i);
    fprintf(f, "%s\n", getAddress);
    fprintf(f, "%s\n", firMove);
    fclose(f);
    lockOrNot = 0;
}

void assJump(char *num1, char *num2, char *i){
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    FILE* f = fopen("ass.asm", "a+");
    fprintf(f, "L%s:\n", i);
    if(num1[0] == '_'){
        char firJmp[30];
        if(num2[0] == '-'){
            sprintf(firJmp, "%s E", jmp);
        }
        else{
            sprintf(firJmp, "%s L%s", jmp, num2);
        }
        fprintf(f, "%s\n", firJmp);
    }
    else{
        char firCmp[30];
        char firJmp[30];
        if(num1[0] == '?' || num1[0] == '@'){
            sprintf(firCmp, "%s [%s], 0", cmp, num1);
        }
        else{
            sprintf(firCmp, "%s %s, 0", cmp, num1);
        }
        if(num2[0] == '-')
        {
        	sprintf(firJmp, "%s E", jg);
		}
		else{
			sprintf(firJmp, "%s L%s", jg, num2);
		}
        fprintf(f, "%s\n", firCmp);
        fprintf(f, "%s\n", firJmp);
    }
    fclose(f);
    lockOrNot = 0;
}

int giveRow()
{
	char s[1024];
	FILE* fp;
	int lines = 0;
	fp = fopen("okk.txt", "r");
	if(fp)
	{
	    while((fgets(s, 1024, fp)) != NULL)
	    {
	    	if(s[strlen(s)-1]=='\n')
			{
				lines++;
			}
		}
	fclose(fp);
	}
	return lines;
}

void saveVary(char*** threeCode, int i, char*** varyCode)
{
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
	sprintf(varyCode[i][0], "%s", threeCode[i][2]);
	sprintf(varyCode[i][1], "%s", threeCode[i][3]);
    FILE* fp = fopen("ass.asm", "a+");
    fprintf(fp, "L%d:\n", i);
    fclose(fp);
    lockOrNot = 0;
}

void readThree(char*** threeCode, char* i, char*** varyCode, int rowNum)
{
	int floor = atoi(i);
	if(strcmp(threeCode[floor][1], "+") == 0)
	{
		assAdd(threeCode[floor][2], threeCode[floor][3], i);
		floor += 1;
	}
	else if(strcmp(threeCode[floor][1], "-") == 0)
	{
		assSub(threeCode[floor][2], threeCode[floor][3], i);
		floor += 1;
	}
	else if(strcmp(threeCode[floor][1], "^") == 0)
	{
		assPow(threeCode[floor][2], threeCode[floor][3], i); 
		floor += 1;
	}
	else if(strcmp(threeCode[floor][1], "*") == 0)
	{
		assMulti(threeCode[floor][2], threeCode[floor][3], i);
		floor += 1;
	}
	else if(strcmp(threeCode[floor][1], "/") == 0)
	{
		assDiv(threeCode[floor][2], threeCode[floor][3], i);
		floor += 1;
	}
	else if(strcmp(threeCode[floor][1], "%") == 0)
	{
		assRemainder(threeCode[floor][2], threeCode[floor][3], i);
		floor += 1;
	}
	else if(strcmp(threeCode[floor][1], "=") == 0)
	{
		assAssgin(threeCode[floor][2], threeCode[floor][3], i);
		floor += 1;
	}
	else if(strcmp(threeCode[floor][1], "!") == 0)
	{
		assNot(threeCode[floor][2], i);
		floor += 1;
	}
	else if(strcmp(threeCode[floor][1], "!=") == 0)
	{
		notEqual(threeCode[floor][2], threeCode[floor][3], i);
		floor += 1;
	}
	else if(strcmp(threeCode[floor][1], "==") == 0)
	{
		equalOrNot(threeCode[floor][2], threeCode[floor][3], i);
		floor += 1;
	}
	else if(strcmp(threeCode[floor][1], "<") == 0)
	{
		assLower(threeCode[floor][2], threeCode[floor][3], i);
		floor += 1;
	}
	else if(strcmp(threeCode[floor][1], ">") == 0)
	{
		assGreater(threeCode[floor][2], threeCode[floor][3], i);
		floor += 1;
	}
	else if(strcmp(threeCode[floor][1], "<=") == 0)
	{
		assLowerEqual(threeCode[floor][2], threeCode[floor][3], i);
		floor += 1;
	}
	else if(strcmp(threeCode[floor][1], ">=") == 0)
	{
		assGreaterEqual(threeCode[floor][2], threeCode[floor][3], i);
		floor += 1;
	}
	else if(strcmp(threeCode[floor][1], "in") == 0)
	{
		Input(threeCode[floor][2], i);
		floor += 1;
	}
	else if(strcmp(threeCode[floor][1], "out") == 0)
	{
		Output(threeCode[floor][2], i);
		floor += 1;
	}
	else if(strcmp(threeCode[floor][1], "offset") == 0)
	{
		assOffset(threeCode[floor][2], threeCode[floor][3], i);
		floor += 1;
	}
	else if(strcmp(threeCode[floor][1], "find") == 0)
	{
		assFind(threeCode[floor][2], i);
		floor += 1;
	}
	else if(strcmp(threeCode[floor][1], "&") == 0)
	{
		assGetAddress(threeCode[floor][2], i);
		floor += 1;
	}
	else if(strcmp(threeCode[floor][1], "j") == 0)
	{
		assJump(threeCode[floor][2], threeCode[floor][3], i);
		floor += 1;
	}
	else if(strcmp(threeCode[floor][1], "n") == 0)
	{
		saveVary(threeCode, floor, varyCode);
		floor += 1;
	}
	if(floor < rowNum)
	{
		readThree(threeCode, threeCode[floor][0], varyCode, rowNum);
	}
}

void start(){
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    char exitProcess[30] = "global main\n";
    char codeIdentify[30] = "main:";
    FILE* f = fopen("ass.asm", "a+");
    fprintf(f, "%s\n", exitProcess);
    fprintf(f, "%s\n", codeIdentify);
    fclose(f);
    lockOrNot = 0;
}

void end(char*** varyCode, int rowNum){
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    FILE* f = fopen("ass.asm", "a+");
    char firMove[100] = "E:\nret\n\nsection .data";
    fprintf(f, "%s\n", firMove);
    int i = 0;
    for(; i < rowNum; i++){
        char initRow[30];
        sprintf(initRow, "?%d dw 0", i);
        fprintf(f, "%s\n", initRow);
    }
    for(i = 0; i < rowNum; i++){
        if(strcmp(varyCode[i][0], "") != 0){
            int number = atoi(varyCode[i][1]);
            number = number / 4;
            char initRow[30];
            sprintf(initRow, "%s times %d dw 0", varyCode[i][0], number);
            fprintf(f, "%s\n", initRow);
        }
    }
    fclose(f);
    lockOrNot = 0;
}