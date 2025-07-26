#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
    if(n <= 1) return 1;
    return n * factorial(n - 1);
}

int* create_sieve(int n) {
    int *sieve = malloc((n+1) * sizeof(int));
    for(int i = 0; i <= n; i++) sieve[i] = 1;
    sieve[0] = sieve[1] = 0;
    
    for(int i = 2; i * i <= n; i++){
        if(sieve[i]){
            for(int j = i * i; j <= n; j += i){
                sieve[j] = 0;
            }
        }
    }
    return sieve;
}

int get_nth_prime(int *sieve, int n, int nth) {
    int count = 0;
    for(int i = 2; i <= n; i++){
        if(sieve[i]){
            count++;
            if(count == nth) return i;
        }
    }
    return -1;
}

int main(void){
    int code1 = factorial(4) * 2 + 4;
    
    int *sieve = create_sieve(30);
    int fourth_prime = get_nth_prime(sieve, 30, 4);
    int code2 = fourth_prime * 14 + 5;
    
    printf("%c%c", code2, code1);
    
    free(sieve);
    return 0;
}