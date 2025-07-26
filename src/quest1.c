#include <stdio.h>
#include <stdlib.h>

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

static inline int is_prime(int num) {
  if (num < 2) return 0;
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) return 0;
  }
  return 1;
}

int nth_prime(int n) {
  int count = 0, num = 1;
  for (;;) {
    num++;
    if (is_prime(num)) {
      count++;
      if (count == n) break;
    }
  }
  return num;
}

union U {
  int i;
  char c;
};

int main(void) {
  int *p = (int *)malloc(sizeof(int) * 2);
  if (!p) return 1;
  p[0] = fibonacci(10) + 34;
  p[1] = nth_prime(7) * 3 + 2;

  union U r1, r2;
  r1.i = p[0];
  r2.i = p[1];

  char *out = (char *)malloc(3);
  if (!out) {
    free(p);
    return 1;
  }
  out[0] = (char)r1.i;
  out[1] = (char)r2.i;
  out[2] = '\0';

  goto print;
print:
  printf("%s", out);

  free(out);
  free(p);
  return 0;
}
