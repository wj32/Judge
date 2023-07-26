class Solution {
public:
    bool divisorGame(int n) {
        vector<bool> r(n + 1);
        r[1] = false;
        for (int i = 2; i <= n; ++i) {
            r[i] = [&] {
                for (int j = 1; j < i; ++j) {
                    if (i % j == 0 && !r[i - j]) {
                        return true;
                    }
                }
                return false;
            }();
        }
        return r[n];
    }
};