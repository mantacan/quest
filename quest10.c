#include <stdio.h>

int main(void){
    char str[] = "School21";
    int len = 0;
    while(str[len] != '\0') len++;
    
    int first = len * 15 + 1;
    int second = str[0] - 18;
    
    printf("%c%c", first, second);
    
    return 0;
}