class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> v(n);
        v[0] = 1;

        vector<int> p(primes.size(), 0);

        for (int i = 1; i < n; i++) {
            int minimum = numeric_limits<int>::max();
            for (int j = 0; j < primes.size(); j++) {
                minimum = min(minimum, v[p[j]] * primes[j]);
            }

            v[i] = minimum;

            for (int j = 0; j < primes.size(); j++) {
                if (v[p[j]] * primes[j] == minimum) {
                    p[j]++;
                }
            }
        }

        return v[n - 1];
    }
};
