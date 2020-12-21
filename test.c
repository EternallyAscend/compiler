#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char* num1 = "this is";
    int num = 111;
    char* num2;
    sprintf(num2, "%s%d xx", num1, num);
    printf("%s", num2);
    return 0;
}