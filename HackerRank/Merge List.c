#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define P 1000000007

int inverseModP(int m) {
    int t = 0;
    int t2 = 1;
    int r = P;
    int r2 = m;
    
    while (r2 != 0) {
        int q = r / r2;
        int t3;
        int r3;
        t3 = t2;
        t2 = t - q * t2;
        t = t3;
        r3 = r2;
        r2 = r - q * r2;
        r = r3;
    }
    
    if (t < 0) {
        t = t + P;
    }
    
    return t;
}

int multinomialModP(int m, int n) {
    int result = 1;
    int k;
    
    for (k = m + n; k > m; k--) {
        result = (int)(((unsigned long long)result * k) % P);
    }
    
    for (k = 2; k <= n; k++) {
        result = (int)(((unsigned long long)result * inverseModP(k)) % P);
    }
    
    return result;
}

int main() {
    int n;
    int i;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        int m, n;
        scanf("%d %d", &m, &n);
        printf("%d\n", multinomialModP(m, n));
    }
    return 0;
}
