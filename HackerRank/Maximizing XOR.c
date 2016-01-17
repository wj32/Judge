#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
/*
 * Complete the function below.
 */
int maxXor(int l, int r) {
    int i, j;
    int result = 0;
    
    for (i = l; i < r; i++) {
        for (j = i + 1; j <= r; j++) {
            if (result < (i ^ j))
                result = i ^ j;
        }
    }
    
    return result;
}
int main() {
    int res;
    int _l;
    scanf("%d", &_l);
    
    int _r;
    scanf("%d", &_r);
    
    res = maxXor(_l, _r);
    printf("%d", res);
    
    return 0;
}
