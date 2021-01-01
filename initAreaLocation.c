#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"

int intCount = 0;
int addCount = 0;
int multiCount = 0;
int subCount = 0;
int divCount = 0;
int remCount = 0;
int powCount = 0;
int assignCount = 0;
int cmpEqualCount = 0;
int cmpNotEqualCount = 0;
int cmpGreaterCount = 0;
int cmpGreaterEqualCount = 0;
int cmpLowerCount = 0;
int cmpLowerEqualCount = 0;
// int cmpAndCount = 0;
// int cmpOrCount = 0;
// int cmpNotCount = 0;

char* initAssign() {
    char* name;
    sprintf(name, "assignCount%d", assignCount);
    assignCount++;
    return name;
}

char* initInt() {
    char* name;
    sprintf(name, "intCount%d", intCount);
    intCount++;
    return name;
}

char* initAdd() {
    char* name;
    sprintf(name, "addCount%d", addCount);
    addCount++;
    return name;
}

char* initMulti() {
    char* name;
    sprintf(name, "multiCount%d", multiCount);
    multiCount++;
    return name;
}

char* initSub() {
    char* name;
    sprintf(name, "subCount%d", subCount);
    subCount++;
    return name;
}

char* initDiv() {
    char* name;
    sprintf(name, "divCount%d", divCount);
    divCount++;
    return name;
}

char* initRem() {
    char* name;
    sprintf(name, "remCount%d", remCount);
    remCount++;
    return name;
}

char* initPow() {
    char* name;
    sprintf(name, "powCount%d", powCount);
    powCount++;
    return name;
}

char* initCmpEqual() {
    char* name;
    sprintf(name, "cmpEqualCount%d", cmpEqualCount);
    cmpEqualCount++;
    return name;
}

char* initCmpNotEqual() {
    char* name;
    sprintf(name, "cmpNotEqualCount%d", cmpNotEqualCount);
    cmpNotEqualCount++;
    return name;
}

char* initCmpGreater() {
    char* name;
    sprintf(name, "cmpGreaterCount%d", cmpGreaterCount);
    cmpGreaterCount++;
    return name;
}

char* initCmpGreaterEqual() {
    char* name;
    sprintf(name, "cmpGreaterEqualCount%d", cmpGreaterEqualCount);
    cmpGreaterEqualCount++;
    return name;
}

char* initCmpLower() {
    char* name;
    sprintf(name, "cmpLowerCount%d", cmpLowerCount);
    cmpLowerCount++;
    return name;
}

char* initCmpLowerEqual() {
    char* name;
    sprintf(name, "cmpLowerEqualCount%d", cmpLowerEqualCount);
    cmpLowerEqualCount++;
    return name;
}

// char* initAnd() {
//     char* name;
//     sprintf(name, "cmpAndCount%d", cmpAndCount);
//     cmpAndCount++;
//     return name;
// }

// char* initOr() {
//     char* name;
//     sprintf(name, "cmpOrCount%d", cmpOrCount);
//     cmpOrCount++;
//     return name;
// }

// char* initNot() {
//     char* name;
//     sprintf(name, "cmpNotCount%d", cmpNotCount);
//     cmpNotCount++;
//     return name;
// }