class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int prime = 1000000007;
        vector<int> r(high + 1);
        r[0] = 1;
        for (int i = 1; i <= high; ++i) {
            r[i] = ((i >= zero ? r[i - zero] : 0) + (i >= one ? r[i - one] : 0)) % prime;
        }
        int sum = 0;
        for (int i = low; i <= high; ++i) {
            sum = (sum + r[i]) % prime;
        }
        return sum;
    }
};