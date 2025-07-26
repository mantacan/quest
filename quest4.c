#include <stdio.h>

int main(void){
    int first = 8 * 8 + 10;
    int second = (14 * 15) / 2 + 3;
    
    for(int i = 7; i >= 0; i--){
        printf("%d", (first >> i) & 1);
    }
    for(int i = 7; i >= 0; i--){
        printf("%d", (second >> i) & 1);
    }
    
    return 0;
}