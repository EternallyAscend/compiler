#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "file.h"
#include "ass.h"
int lockOrNot = 0;
char mov[] = "MOV";
char add[] = "ADD";
char sub[] = "SUB";
char imul[] = "IMUL";
char cmp[] = "CMP";
char idiv[] ="IDIV";
char jnb[] = "JNB";
char jb[] = "JB";
char je[] = "JE";
char jne[] = "JNE";
char jna[] = "JNA";
char ja[] = "JA";
char jg[] = "JG";
char jmp[] = "JMP";
char lea[] = "LEA";
char in[] = "IN";
char out[] = "OUT";
char setge[] = "SETGE";
char setg[] = "SETG";
char setl[] = "SETL";
char setle[] = "SETLE";
char setne[] = "SETNE";

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
    else if(num1[0] == '$')
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
    else if(num2[0] == '$')
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
        sprintf(secMove, "%s %s, [%s]", mov, bx, num2);
    }
    else{
        sprintf(secMove, "%s %s, %s", mov, bx, num2);
    }
    sprintf(firAssign, "%s %s, %s", mov, ax, bx);
    sprintf(storageResult, "%s [?%s], %s", mov, i, ax);
    FILE* f = fopen("ass.asm", "a+");
    fprintf(f, "L%s:\n", i);
    fprintf(f, "%s\n", firMove);
    fprintf(f, "%s\n", secMove);
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
    sprintf(storageResult, "%s [?%s], %s", mov, i, zf);
    FILE* f = fopen("ass.asm", "a+");
    fprintf(f, "L%s:\n", i);
    fprintf(f, "%s\n", firMove);
    fprintf(f, "%s\n", getNot);
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
    sprintf(compare, "%s %s, %s", cmp, ax, bx);
    sprintf(result, "%s %s", setne, zf);
    sprintf(storageResult, "%s [?%s], %s", mov, i, zf);
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
    char storageResult[30];
    char result[30];
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
    sprintf(compare, "%s %s, %s", cmp, ax, bx);
    sprintf(storageResult, "%s [?%s],%s", mov, i, zf);
    FILE* f = fopen("ass.asm", "a+");
    fprintf(f, "L%s:\n", i);
    fprintf(f, "%s\n", firMove);
    fprintf(f, "%s\n", secMove);
    fprintf(f, "%s\n", compare);
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
    sprintf(compare, "%s %s, %s", cmp, ax, bx);
    sprintf(result, "%s %s", setl, cf);
    sprintf(storageResult, "%s [?%s], %s", mov, i, cf);
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
    sprintf(compare, "%s %s, %s", cmp, ax, bx);
    sprintf(result, "%s %s", setle, cf);
    sprintf(storageResult, "%s [?%s], %s", mov, i, cf);
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
    sprintf(compare, "%s %s, %s", cmp, ax, bx);
    sprintf(result, "%s %s", setg, cf);
    sprintf(storageResult, "%s [?%s], %s", mov, i, cf);
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
    sprintf(compare, "%s %s, %s", cmp, ax, bx);
    sprintf(result, "%s %s", setge, cf);
    sprintf(storageResult, "%s [?%s], %s", mov, i, cf);
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
     else if(num1[0] == '$')
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
     else if(num1[0] == '$')
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
    char firMove[30];
    char secMove[30];
    char thiMove[30];
    char firAdd[30];
    sprintf(getAddress, "%s %s, [%s]", lea, ax, num1);
    if(num2[0] == '?' || num2[0] == '$')
    {
        sprintf(firAdd, "%s %s, [%s]", add, ax, num2);
    }
    else{
        sprintf(firAdd, "%s %s, %s", mov, bx, num2);
    }
    sprintf(firMove, "%s %s, %s", mov, bx, ax);
    sprintf(secMove, "%s %s, [%s]", mov, ax, bx);
    sprintf(thiMove, "%s [?%s], %s", mov, i, ax);
    FILE* f = fopen("ass.asm", "a+");
    fprintf(f, "L%s:\n", i);
    fprintf(f, "%s\n", getAddress);
    fprintf(f, "%s\n", firAdd);
    fprintf(f, "%s\n", firMove);
    fprintf(f, "%s\n", secMove);
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
    sprintf(getAddress, "%s %s, %s", lea, ax, num1);
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
            sprintf(firJmp, "%s End", jmp);
        }
        else{
            sprintf(firJmp, "%s L%s", jmp, num2);
        }
        fprintf(f, "%s\n", firJmp);
    }
    else{
        char firCmp[30];
        char firJmp[30];
        if(num1[0] == '?' || num1[0] == '$'){
            sprintf(firCmp, "%s [%s], 0", cmp, num1);
        }
        else{
            sprintf(firCmp, "%s %s, 0", cmp, num1);
        }
        if(num2[0] == '-')
        {
        	sprintf(firJmp, "%s End", jg);
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
	sprintf(varyCode[i][0], "%s", threeCode[i][2]);
	sprintf(varyCode[i][1], "%s", threeCode[i][3]);
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

void start(char*** varyCode, int rowNum){

}

void end(){

}