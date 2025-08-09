#include <stdio.h>
#include <stdlib.h>

static inline int calculate_first() { return (1 << 4) | (1 << 1) | (1 << 0); }

int main(void) {
  int *result = malloc(sizeof(int));
  *result = calculate_first();

  printf("%d\n", *result);

  free(result);
  return 0;
}