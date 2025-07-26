#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char* buffer = malloc(5);
    strcpy(buffer, "UlA=");
    
    char* s1 = malloc(5);
    for (int i = 0; i < 4; i++) {
        s1[i] = buffer[i] ^ 0x01;
    }
    s1[4] = '\0';
    
    char* s2 = malloc(5);
    for (int i = 0; i < 4; i++) {
        s2[i] = s1[i] + 1;
    }
    s2[4] = '\0';
    
    printf("%s\n", s2);
    
    free(buffer);
    free(s1);
    free(s2);
    
    return 0;
}