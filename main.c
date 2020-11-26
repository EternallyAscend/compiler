#include <stdio.h>

#include "table.h"

int main() {
    char* name = "name";
    printf("%s\n", name);
    printf("%d\n", NULL == name);
    printf("%d\n", getNameHash(name, 11));
    launchTable();
    printf("%d\n", nextSize(2));
    printf("%d\n", nextSize(7));
    printf("%d\n", nextSize(9));
    push();
    push();
    printf("0x%d\n", add("tom", 1));
    printf("0x%d\n", add("Symbian", 1));
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
    printf("0x%d\n", add("value0", 1));
    push();
    printf("0x%d\n", add("value1", 1));
    printf("0x%d\n", add("value2", 1));
    pop();
    printf("0x%d\n", add("value3", 1));
    pop();
    push();
    push();
    push();
    push();
    push();
    push();
    push();
    printf("0x%d\n", add("value4", 1));
    printf("0x%d\n", add("value5", 1));
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
    printf("0x%d\n", add("value6", 1));
    printf("0x%d\n", add("value7", 1));
    printf("0x%d\n", add("value8", 1));
    printf("0x%d\n", add("value9", 1));
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
