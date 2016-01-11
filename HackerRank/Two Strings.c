#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_STRING_SIZE 100000

char a[MAX_STRING_SIZE + 1];
char b[MAX_STRING_SIZE + 1];

// a and b have a common substring if and only if they have a character in common.
int commonSubstring(int m, int n) {
    char pa[256] = { 0 };
    char pb[256] = { 0 };
    int i;
    
    for (i = 0; i < m; i++) {
        pa[(unsigned char)a[i]] = 1;
    }
    
    for (i = 0; i < n; i++) {
        pb[(unsigned char)b[i]] = 1;
    }
    
    for (i = 0; i < 256; i++) {
        if (pa[i] && pb[i]) {
            return 1;
        }
    }
    
    return 0;
}

int main() {
    int t;
    int i;
    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        scanf("%s", a);
        scanf("%s", b);
        printf("%s\n", commonSubstring(strlen(a), strlen(b)) ? "YES" : "NO");
    }
    return 0;
}
