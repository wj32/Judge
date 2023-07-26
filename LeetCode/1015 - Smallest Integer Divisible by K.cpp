class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int n = 1 % k;
        vector<bool> seen(k);
        for (int i = 1; ; ++i) {
            if (n == 0) {
                return i;
            }
            if (seen[n]) {
                return -1;
            }
            seen[n] = true;
            n = (n * 10 + 1) % k;
        }
    }
};