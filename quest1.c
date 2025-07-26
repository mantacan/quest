#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, temp;
    for (int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int is_prime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int nth_prime(int n) {
    int count = 0, num = 2;
    while (count < n) {
        if (is_prime(num)) count++;
        if (count < n) num++;
    }
    return num;
}

int main(void) {
    int fib_result = fibonacci(10) + 34;
    int prime_result = nth_prime(7) * 3 + 2;
    
    printf("%c%c\n", fib_result, prime_result);
    
    return 0;
}