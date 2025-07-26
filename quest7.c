#include <stdio.h>

int main(void){
    int first = ((('`' + 1) << 1) & 194) >> 1;
    int second = (('A' + 1) | 6) - 1 + 2;
    
    printf("%d%d", first, second);
    
    return 0;
}