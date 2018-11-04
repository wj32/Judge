class Solution {
public:
    int numTrees(int n) {
        vector<int> r(n + 1, 0);
        r[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                r[i] += r[j] * r[i - j - 1];
            }
        }
        return r[n];
    }
};
