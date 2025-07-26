#include <stdio.h>
#include <string.h>

int factorial(int n) {
  int result = 1;
  for (int i = 1; i <= n; i++) {
    result *= i;
  }
  return result;
}

int sum_of_digits(int num) {
  int sum = 0;
  while (num > 0) {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}

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

char atbash(char c) {
  if (c >= 'A' && c <= 'Z') {
    return 'Z' - (c - 'A');
  }
  if (c >= 'a' && c <= 'z') {
    return 'z' - (c - 'a');
  }
  return c;
}

int main(void) {
  int fact7 = factorial(7);
  int digit_sum = sum_of_digits(fact7);
  int result_a = digit_sum * 7 + 8;

  int fib11 = fibonacci(11);
  int result_b = fib11 - 4;

  char ascii_a = (char)result_a;
  char ascii_b = (char)result_b;

  char cipher_a = atbash(ascii_a);
  char cipher_b = atbash(ascii_b);

  printf("%c%c\n", cipher_b, cipher_a + 32);

  return 0;
}