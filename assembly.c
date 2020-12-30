#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"
int lockOrNot = 0;
char mov[] = "MOV";
char add[] = "ADD";
char cmp[] = "CMP";
char idiv[] ="IDIV";
char jnb[] = "JNB";
char jb[] = "JB";
char je[] = "JE";
char jne[] = "JNE";
char jna[] = "JNA";
char ja[] = "JA";
char or[] = "OR";
char in[] = "IN";
char out[] = "OUT";
char setge[] = "SETGE";
char setg[] = "SETG";
char setl[] = "SETL";
char setle[] = "SETLE";
char setne[] = "SETNE";
char not[] = "NOT";

char ax[] = "eax";
char bx[] = "ebx";
char cx[] = "ecx";
char zf[] = "zf";
char ah[] = "ah";
char cf[] = "cf";
char sf[] = "sf";

void start(){
                                                                                              
}

void end(){
    
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

/*void assMulti(char* num1, char* num2) {
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    char count[30];
    char firMove[30];
    char secMove[30];
    char thiMove[30];
    char loop[30];
    char storageResult[30];
      if(num1[0] == '#')
    {
        sprintf(firMove, "%s %s, [%s]", mov, ax, num1);
        sprintf(secMove, "%s %s, [%s]", mov, cx, num1);
    } 
    else if(num1[0] == '@')
    {
        sprintf(firMove, "%s %s, [%s]", mov, ax, num1);
        sprintf(secMove, "%s %s, [%s]", mov, cx, num1);
    }
    else{
        sprintf(firMove, "%s %s, %s", mov, ax, num1);
        sprintf(secMove, "%s %s, %s", mov, cx, num1);
    }
    if(num2[0] == '#')
    {
        sprintf(thiMove, "%s %s, [%s]", mov, bx, num2);
    }
    else if(num2[0] == '@')
    {
        sprintf(thiMove, "%s %s, [%s]", mov, bx, num2);
    }
    else{
        sprintf(thiMove, "%s %s, %s", mov, bx, num2);
    }
    sprintf(loop, "m%s: %s %s, %s\n  loop m%s", bx, add, ax, cx, bx);
    sprintf(storageResult, " [?%s]", ax);//put ax to stroge
    fclose(f);
    lockOrNot = 0;
}*/

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
    sprintf(compare, "%s %s, %d", cmp, ax, bx);
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
    sprintf(compare, "%s %s, %d", cmp, ax, bx);
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

// 第一个变量为操作数 第二个为端口地址，输出同理
void Input(char* num1, char* i) {
   while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    char firMove[30];
    char secMove[30];
    char getin[30];
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
    /*if(num2[0] == '#')
    {
        sprintf(secMove, "%s %s, [%s]", mov, bx, num2);
    }
     else if(num2[0] == '@')
    {
        sprintf(secMove, "%s %s, [%s]", mov, bx, num2);
    }
    else{
        sprintf(secMove, "%s %s, %s", mov, bx, num2);
    }*/
    sprintf(getin, "%s %s, 21H", in, ax);
    FILE* f = fopen("ass.asm", "a+");
    fprintf(f, "L%s:\n", i);
    fprintf(f, "%s\n", firMove);
    // fprintf(f, "%s\n", secMove);
    fprintf(f, "%s\n", getin);
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
/*if(num2[0] == '#')
    {
        sprintf(secMove, "%s %s, [%s]", mov, bx, num2);
    }
     else if(num2[0] == '@')
    {
        sprintf(secMove, "%s %s, [%s]", mov, bx, num2);
    }
    else{
        sprintf(secMove, "%s %s, %s", mov, bx, num2);
    }*/
    sprintf(getout, "%s 378H, %s", out, ax);
    FILE* f = fopen("ass.asm", "a+");
    fprintf(f, "L%s:\n", i);
    fprintf(f, "%s\n", firMove);
    // fprintf(f, "%s\n", secMove);
    fprintf(f, "%s\n", getout);
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
    sprintf(storageResult, "%s [?%s], %s", mov, i, zf)
    FILE* f = fopen("ass.asm", "a+");
    fprintf(f, "L%s:\n", i);
    fprintf(f, "%s\n", firMove);
    fprintf(f, "%s\n", getNot);
    fprintf(f, "%s\n", storageResult);
    fclose(f);
    lockOrNot = 0;
}