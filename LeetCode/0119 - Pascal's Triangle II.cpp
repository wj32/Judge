class Solution {
public:
    vector<int> getRow(int k) {
        vector<int> r(k + 1);
        r[0] = 1;
        for (int j = 1; j <= k; j++) {
            r[j] = static_cast<int>(static_cast<long long>(r[j - 1]) * (k - j + 1) / j);
        }
        return r;
    }
};
