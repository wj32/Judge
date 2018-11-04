class Solution {
public:
    bool recurse(const string& s1, size_t b1, const string& s2, size_t b2, size_t n) {
        if (n <= 3) {
            return true;
        }

        array<int, 256> d{};
        int mismatched = 0;

        const auto adjust = [&](unsigned char c1, unsigned char c2) {
            if (c1 != c2) {
                d[c1]++;
                if (d[c1] == 0) {
                    mismatched--;
                }
                else if (d[c1] == 1) {
                    mismatched++;
                }

                d[c2]--;
                if (d[c2] == 0) {
                    mismatched--;
                }
                else if (d[c2] == -1) {
                    mismatched++;
                }
            }
        };

        for (int i = 0; i < n - 1; i++) {
            adjust(s1[b1 + i], s2[b2 + i]);

            if (mismatched == 0) {
                if (recurse(s1, b1, s2, b2, i + 1) &&
                    recurse(s1, b1 + i + 1, s2, b2 + i + 1, n - (i + 1))) {
                    return true;
                }
            }
        }

        d = {};
        mismatched = 0;

        for (int i = 0; i < n - 1; i++) {
            adjust(s1[b1 + i], s2[b2 + n - 1 - i]);

            if (mismatched == 0) {
                if (recurse(s1, b1, s2, b2 + n - (i + 1), i + 1) &&
                    recurse(s1, b1 + i + 1, s2, b2, n - (i + 1))) {
                    return true;
                }
            }
        }

        return false;
    }

    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }

        const auto n = s1.size();
        array<int, 256> d{};

        for (int i = 0; i < n; i++) {
            d[static_cast<unsigned char>(s1[i])]++;
            d[static_cast<unsigned char>(s2[i])]--;
        }

        for (const auto x : d) {
            if (x != 0) {
                return false;
            }
        }

        return recurse(s1, 0, s2, 0, n);
    }
};
