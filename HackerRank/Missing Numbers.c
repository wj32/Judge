#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_NUMBER 10100

void readAndUpdateFreq(int *freq, int n) {
    int i;
    
    for (i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        freq[x]++;
    }
}

int main() {
    int i;
    int n, m;
    int aFreq[MAX_NUMBER + 1] = { 0 };
    int bFreq[MAX_NUMBER + 1] = { 0 };
    int notFirst = 0;
    
    scanf("%d", &n);
    readAndUpdateFreq(aFreq, n);
    scanf("%d", &m);
    readAndUpdateFreq(bFreq, m);
    
    for (i = 1; i <= MAX_NUMBER; i++) {
        if (aFreq[i] < bFreq[i]) {
            printf("%s%d", notFirst ? " " : "", i);
            notFirst = 1;
        }
    }
    
    return 0;
}
