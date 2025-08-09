#include <stdio.h>
#include <stdlib.h>

int *create_sieve(int n) {
  int *sieve = (int *)malloc((n + 1) * sizeof(int));
  for (int i = 0; i <= n; i++) sieve[i] = 1;
  sieve[0] = sieve[1] = 0;

  for (int i = 2; i * i <= n; i++) {
    if (sieve[i]) {
      for (int j = i * i; j <= n; j += i) {
        sieve[j] = 0;
      }
    }
  }
  return sieve;
}

int count_primes(int *sieve, int n) {
  int count = 0;
  for (int i = 2; i <= n; i++) {
    if (sieve[i]) count++;
  }
  return count;
}

int get_nth_prime(int *sieve, int n, int nth) {
  int count = 0;
  for (int i = 2; i <= n; i++) {
    if (sieve[i]) {
      count++;
      if (count == nth) return i;
    }
  }
  return -1;
}

int main(void) {
  int *sieve = create_sieve(200);

  int count = count_primes(sieve, 200);
  int code1 = (count * 7 + 11) % 256 + 2;
  int code2 = get_nth_prime(sieve, 200, 23) + 2;

  printf("%c%c", code1, code2);

  free(sieve);
  return 0;
}