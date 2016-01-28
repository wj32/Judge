#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

int testCase(vector<int>& xs) {
    if (xs.size() == 0) {
        return 0;
    }
    
    multiset<pair<int, int>> s;
    
    sort(xs.begin(), xs.end());
    for (auto x : xs) {
        auto it = s.lower_bound(make_pair(x - 1, 0));
        int count = 0;
        
        if (it != s.end() && it->first == x - 1) {
            count = it->second;
            s.erase(it);
        }
        
        s.insert(make_pair(x, count + 1));
    }
    
    int minCount = numeric_limits<int>::max();
    for (auto& p : s) {
        int count = p.second;
        if (minCount > count) {
            minCount = count;
        }
    }
    
    return minCount;
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        
        vector<int> xs;
        xs.reserve(n);
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            xs.push_back(x);
        }
        
        cout << testCase(xs) << endl;
    }
    
    return 0;
}
