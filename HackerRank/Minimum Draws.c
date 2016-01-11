#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int t;
    int i;
    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        printf("%d\n", n + 1);
    }
    return 0;
}
