#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        pq.push(a);
    }
    
    int operations = 0;
    while (pq.top() < k && pq.size() >= 2) {
        int cookie1 = pq.top();
        pq.pop();
        int cookie2 = pq.top();
        pq.pop();
        pq.push(cookie1 + 2 * cookie2);
        operations++;
    }
    
    cout << (pq.top() >= k ? operations : -1);
    
    return 0;
}
