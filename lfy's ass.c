#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"
#include "ass.h"

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
char jmp[] = "JMP";
char lea[] = "LEA"
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

void assFind(char *num1, char *i){
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    char firMove[30];
    char secMove[30];
    char thiMove[30];
    sprintf(firMove, "%s %s, %s", mov, bx, num1);
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

void assOffset(char *num1, char *num2, char *i){
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    char getAddress[30];
    char firMove[30];
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

void assJump(char *num1, char *num2, char *i){
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    FILE* f = fopen("ass.asm", "a+");
    fprintf(f, "L%s:\n", i);
    if(num1[0] == '_'){
        char firJmp[30];
        if(num2[0] < '-'){
            sprintf(firJmp, "%s End", jmp);
        }
        else{
            sprintf(firJmp, "%s L%s", jmp, num2)
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
        sprintf(firJmp, "%s L%s", jmp, num2);
        fprintf(f, "%s\n", firCmp);
        fprintf(f, "%s\n", firJmp);
    }
    fclose(f);
    lockOrNot = 0;
}