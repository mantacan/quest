#include <stdio.h>

int square(int n) { return n * n; }

int triangular_number(int n) { return n * (n + 1) / 2; }

int calculate_first_symbol() { return square(11) - 45; }

int calculate_second_symbol() { return triangular_number(11) + 9; }

int main(void) {
  int symbol1 = calculate_first_symbol();
  int symbol2 = calculate_second_symbol();

  printf("%c%c\n", symbol1, symbol2);

  return 0;
}