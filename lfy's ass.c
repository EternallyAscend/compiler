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
    FILE* f = fopen("ass.asm", 'a+');
    fprint(f, "L%s:\n", i);
    fprint(f, "%s\n", getAddress);
    fprint(f, "%s\n", firMove);
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
    FILE* f = fopen("ass.asm", 'a+');
    fprint(f, "L%s:\n", i);
    fprint(f, "%s\n", firMove);
    fprint(f, "%s\n", secMove);
    fprint(f, "%s\n", thiMove);
    lockOrNot = 0;
}

void assOffset(char *num1, char *num2, char *i){
    while(lockOrNot == 1) {
        sleep(1);
    }
    lockOrNot = 1;
    sprintf(firMove, "%s %s, %s", mov, bx, num1);
    FILE* f = fopen("ass.asm", 'a+');
    fprint(f, "L%s:\n", i);
    fprint(f, "%s\n", firMove);
    lockOrNot = 0;
}

void assJump(char *num1, char *num2, char *i){
}