#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    
    auto a = new bool*[m];
    for (int i = 0; i < m; i++) {
        a[i] = new bool[n]{};
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            a[i][j] = s[j] == 'x';
        }
    }
    
    auto blockedLeft = new int*[m];
    auto blockedUp = new int*[m];
    for (int i = 0; i < m; i++) {
        blockedLeft[i] = new int[n]{};
        blockedUp[i] = new int[n]{};
    }
    
    for (int i = 0; i < m; i++) {
        int previous = -1;
        for (int j = 0; j < n; j++) {
            if (a[i][j]) {
                previous = j;
            }
            blockedLeft[i][j] = previous;
        }
    }
    
    for (int j = 0; j < n; j++) {
        int previous = -1;
        for (int i = 0; i < m; i++) {
            if (a[i][j]) {
                previous = i;
            }
            blockedUp[i][j] = previous;
        }
    }
    
    int maxPerimeter = 0;
    
    for (int top = 0; top < m - 1; top++) {
        for (int left = 0; left < n - 1; left++) {
            if (a[top][left]) {
                continue;
            }
            
            for (int bottom = top + 1; bottom < m; bottom++) {
                if (blockedUp[bottom][left] >= top) {
                    continue;
                }
                
                int right = n - 1;
                int perimeter = 2 * (bottom - top + right - left);
                
                for (; right > left && maxPerimeter < perimeter; right--, perimeter -= 2) {
                    if (blockedLeft[top][right] >= left) {
                        continue;
                    }
                    if (blockedLeft[bottom][right] >= left) {
                        continue;
                    }
                    if (blockedUp[bottom][right] >= top) {
                        continue;
                    }
                    
                    maxPerimeter = perimeter;
                }
            }
        }
    }
    
    if (maxPerimeter != 0) {
        cout << maxPerimeter << endl;
    } else {
        cout << "impossible" << endl;
    }
    
    return 0;
}
