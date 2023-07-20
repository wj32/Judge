class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        static const array<pair<int, int>, 7> table{{
            {1, 1},
            {5, 3},
            {5 * 5, 5},
            {5 * 5 * 5, 7},
            {5 * 5 * 5 * 5, 10},
            {5 * 5 * 5 * 5 * 5, 12},
            {5 * 5 * 5 * 5 * 5 * 5, 14},
        }};
        if (s.front() == '0') {
            return -1;
        }
        int n;
        from_chars(s.data(), s.data() + s.size(), n, 2);
        vector<int> r(s.size() + 1, static_cast<int>(s.size() + 1));
        r[0] = 0;
        for (size_t i = 1; i <= s.size(); ++i) {
            const auto k = n >> (s.size() - i);
            for (const auto& [value, bits] : table) {
                if ((k & ((1 << bits) - 1)) == value) {
                    r[i] = min(r[i], r[i - bits] + 1);
                }
            }
        }
        return r.back() <= s.size() ? r.back() : -1;
    }
};