class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        array<char, 256> a = {};
        array<char, 256> b = {};

        for (int i = 0; i < s.size(); i++) {
            const auto x = &a[static_cast<unsigned char>(s[i])];
            const auto y = &b[static_cast<unsigned char>(t[i])];

            if ((*x == '\0') && (*y == '\0')) {
                *x = t[i];
                *y = s[i];
            }
            else {
                if ((*x != t[i]) || (*y != s[i])) {
                    return false;
                }
            }
        }

        return true;
    }
};
