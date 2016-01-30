#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int q;
    cin >> q;
    
    set<int> s;
    
    for (int i = 0; i < q; i++) {
        int t, v;
        cin >> t;
        
        switch (t) {
        case 1:
            cin >> v;
            s.insert(v);
            break;
        case 2:
            cin >> v;
            s.erase(s.find(v));
            break;
        case 3:
            cout << *s.begin() << endl;
            break;
        }
    }
    
    return 0;
}
