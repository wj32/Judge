class Solution {
public:
    int countPrimes(int n) {
        vector<bool> a(n, true);
        const int limit = static_cast<int>(sqrt(n));
        for (int i = 2; i <= limit; i++) {
            if (a[i]) {
                for (int j = i * 2; j < n; j += i) {
                    a[j] = false;
                }
            }
        }

        int count = 0;
        for (int i = 2; i < n; i++) {
            count += a[i];
        }
        return count;
    }
};
