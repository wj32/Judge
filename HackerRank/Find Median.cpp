#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    priority_queue<int, vector<int>, less<int>> lower;
    priority_queue<int, vector<int>, greater<int>> higher;
    float median;
    bool medianExists = false;
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        
        if (!medianExists) {
            lower.push(a);
            median = a;
            medianExists = true;
        } else {
            if (a <= median) {
                lower.push(a);
                if (lower.size() > higher.size() + 1) {
                    higher.push(lower.top());
                    lower.pop();
                }
            } else {
                higher.push(a);
                if (higher.size() > lower.size() + 1) {
                    lower.push(higher.top());
                    higher.pop();
                }
            }
            
            if (lower.size() == higher.size() + 1) {
                median = lower.top();
            } else if (higher.size() == lower.size() + 1) {
                median = higher.top();
            } else {
                median = (float)(lower.top() + higher.top()) / 2;
            }
        }
        
        printf("%.1f\n", median);
    }
    
    return 0;
}
