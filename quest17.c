#include <stdio.h>

int main(void) {
    char original[] = "<H";
    char s1[3];
    char s2[3];
    
    for (int i = 0; i < 2; i++) {
        if (original[i] >= 'A' && original[i] <= 'Z') {
            s1[i] = 'A' + 'Z' - original[i];
        } else {
            s1[i] = original[i];
        }
    }
    s1[2] = '\0';
    
    for (int i = 0; i < 2; i++) {
        s2[i] = s1[i] + 2;
    }
    s2[2] = '\0';
    
    printf("%s\n", s2);
    
    return 0;
}