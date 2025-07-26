#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int fib_recursive(int n) {
    if(n <= 1) return n;
    return fib_recursive(n-1) + fib_recursive(n-2);
}

int* generate_fib_array(int length) {
    int *arr = malloc(length * sizeof(int));
    for(int i = 0; i < length; i++) {
        arr[i] = fib_recursive(i);
    }
    return arr;
}

bool miller_rabin_test(int n) {
    if(n == 2 || n == 3) return true;
    if(n < 2 || n % 2 == 0) return false;
    
    int d = n - 1;
    int r = 0;
    while(d % 2 == 0) {
        d /= 2;
        r++;
    }
    
    int a = 2;
    int x = 1;
    int temp = d;
    int base = a;
    while(temp > 0) {
        if(temp % 2 == 1) {
            x = (x * base) % n;
        }
        base = (base * base) % n;
        temp /= 2;
    }
    
    if(x == 1 || x == n-1) return true;
    
    for(int i = 0; i < r-1; i++) {
        x = (x * x) % n;
        if(x == n-1) return true;
    }
    return false;
}

void print_binary_8bit(int num) {
    for(int i = 7; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

int main(void){
    int *fib_array = generate_fib_array(12);
    int A = fib_array[8];
    
    int B = 0;
    if(miller_rabin_test(97)) {
        B = 11 * 2 - 3;
    }
    
    int W = (A << 8) | B;
    
    print_binary_8bit((W >> 8) & 0xFF);
    printf(" ");
    print_binary_8bit(W & 0xFF);
    
    free(fib_array);
    return 0;
}