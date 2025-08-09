#include <stdio.h>

int main(void) {
  int first = 8 * 8 + 9;

  int fib = 0, next = 1, temp;
  for (int i = 0; i < 9; i++) {
    temp = fib + next;
    fib = next;
    next = temp;
  }
  int second = fib + 36;

  printf("%d%d", first, second);

  return 0;
}