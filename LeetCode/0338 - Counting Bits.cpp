class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> r(num + 1);
        r[0] = 0;
        for (int i = 1; i <= num; i++) {
            r[i] = r[i / 2] + (i % 2);
        }
        return r;
    }
};
