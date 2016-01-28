#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<tuple<int, int, string>> v;
    
    for (int i = 0; i < n; i++) {
        int x;
        string s;
        cin >> x >> s;
        if (i < n / 2) {
            s = "-";
        }
        v.push_back(make_tuple(x, i, s));
    }
    
    sort(v.begin(), v.end());
    
    string output;
    
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            output.append(" ");
        }
        output.append(get<2>(v[i]));
    }
    
    cout << output;
    
    return 0;
}
