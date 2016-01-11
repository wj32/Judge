#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    int i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        printf("%d %d\n", c + (c - a), d + (d - b));
    }
    return 0;
}
