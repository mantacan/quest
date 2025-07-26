#include <stdio.h>

int main(void) {
    int W = ('B' << 8) | 'u';
    printf("%04X\n", W);
    return 0;
}