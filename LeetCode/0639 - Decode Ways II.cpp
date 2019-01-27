class Solution {
public:
    int numDecodings(string s) {
        const int prime = 1000000007;
        const auto n = s.size();
        vector<long long> r(n + 1);

        r[n] = 1;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != '0') {
                const int multiplier0 = (s[i] == '*') ? 9 : 1;

                r[i] = multiplier0 * r[i + 1];

                if (i < n - 1) {
                    if ((s[i] == '1') || (s[i] == '*')) {
                        const int multiplier1 = (s[i + 1] == '*') ? 9 : 1;
                        r[i] += multiplier1 * r[i + 2];
                    }

                    if ((s[i] == '2') || (s[i] == '*')) {
                        const int multiplier1 = (s[i + 1] == '*') ? 6 : ((s[i + 1] <= '6') ? 1 : 0);
                        r[i] += multiplier1 * r[i + 2];
                    }
                }

                r[i] %= prime;
            }
            else {
                r[i] = 0;
            }
        }

        return static_cast<int>(r[0]);
    }
};
