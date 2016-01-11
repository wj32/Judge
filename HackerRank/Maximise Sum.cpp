#include <cmath>
#include <cstdio>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long uint64;

uint64 buffer[100000];

uint64 doCase(uint64 *a, uint64 n, uint64 m) {
    set<uint64> partialSums;
    uint64 partialSum = 0;
    uint64 maxSum = 0;
    
    for (int i = 0; i < n; i++) {
        partialSum = (partialSum + a[i]) % m;
        
        // The maximum that could be achieved is sum(a[0 .. i]) - sum(a[0 .. j]) = m - 1 for some j < i.
        // That is, we need sum(a[0 .. j]) = sum(a[0 .. i]) - m + 1 = sum(a[0 .. i]) + 1 mod m.
        // So we should search for the smallest number that is greater than sum(a[0 .. i]).
        
        auto it = partialSums.upper_bound(partialSum);
        
        uint64 sum;
        if (it != partialSums.end()) {
            sum = m + partialSum - *it;
        } else {
            sum = partialSum;
        }
        if (maxSum < sum) {
            maxSum = sum;
        }
        
        partialSums.insert(partialSum);
    }
    
    return maxSum;
}

int main() {
    int dummy;
    int t;
    
    dummy = scanf("%d", &t);
    
    for (int i = 0; i < t; i++) {
        int n;
        uint64 m;
        
        dummy = scanf("%d %llu", &n, &m);
        
        for (int j = 0; j < n; j++) {
            dummy = scanf("%llu", &buffer[j]);
        }
        
        printf("%llu\n", doCase(buffer, n, m));
    }
    return 0;
}
