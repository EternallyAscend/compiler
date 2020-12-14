#include <stdio.h>

#include "file.h"
#include "table.h"

int main() {
    generateLEX();
    generateYACC();
    int cursor = 0;
    for (; cursor < 10; cursor++) {
        appendLEX("lex\n");
        appendYACC("yacc\n");
    }
    closeLEX();
    closeYACC();
    char* name = "name";
    printf("%s\n", name);
    printf("%d\n", NULL == name);
    printf("%d\n", getNameHash(name, 11));
    launchTable();
    printf("%d\n", nextSize(2));
    printf("%d\n", nextSize(7));
    printf("%d\n", nextSize(9));
    printf("0x%d\n", add("PUBLIC"));
    push();
    push();
    printf("0x%d\n", add("tom"));
    printf("0x%d\n", add("Symbian"));
    if (NULL == pull("tom")) {
        printf("Not found tom.\n");
    }
    else {
        printf("%s\n", pull("tom")->name);
    }
    if (NULL == pull("Symbian")) {
        printf("Not found Symbian.\n");
    }
    else {
        printf("%s\n", pull("Symbian")->name);
    }
    if (NULL == pull("value9")) {
        printf("Not found value9.\n");
    }
    else {
        printf("%s\n", pull("value9")->name);
    }
    pop();
    push();
    printf("0x%d\n", add("value0"));
    push();
    printf("0x%d\n", add("value1"));
    printf("0x%d\n", add("value2"));
    pop();
    printf("0x%d\n", add("value3"));
    pop();
    push();
    push();
    push();
    push();
    push();
    push();
    push();
    if (NULL == pull("PUBLIC")) {
        printf("Not found PUBLIC.\n");
    }
    else {
        printf("%s\n", pull("PUBLIC")->name);
    }
    if (NULL == pull("public")) {
        printf("Not found public.\n");
    }
    else {
        printf("%s\n", pull("public")->name);
    }
    printf("0x%d\n", add("value4"));
    printf("0x%d\n", add("value5"));
    if (NULL == pull("value5")) {
        printf("Not found value5.\n");
    }
    else {
        printf("%s\n", pull("value5")->name);
    }
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    printf("0x%d\n", add("value6"));
    printf("0x%d\n", add("value7"));
    printf("0x%d\n", add("value8"));
    printf("0x%d\n", add("value9"));
//    printf("0x%p\n", NULL);
    if (NULL == pull("tom")) {
        printf("Not found tom.\n");
    }
    else {
        printf("%s\n", pull("tom")->name);
    }
    if (NULL == pull("Symbian")) {
        printf("Not found Symbian.\n");
    }
    else {
        printf("%s\n", pull("Symbian")->name);
    }
    if (NULL == pull("value9")) {
        printf("Not found value9.\n");
    }
    else {
        printf("%s\n", pull("value9")->name);
    }
    printf("Before POP.\n");
    pop();
    printf("After POP.\n");
    stopTable();
    return 0;
}
