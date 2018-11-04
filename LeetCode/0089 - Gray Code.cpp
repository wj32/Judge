class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> r;
        r.reserve(1 << n);
        r.push_back(0);

        int k = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                r.push_back(r[k - j - 1] + k);
            }
            k <<= 1;
        }

        return r;
    }
};
