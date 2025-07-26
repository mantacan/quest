#include <stdio.h>

int main(void) {
    int first = 26 - 25;
    
    int primes[4] = {2, 3, 5, 7};
    int second = primes[3] + 16;
    
    printf("%c%c", first + 64, second + 64);
    
    return 0;
}