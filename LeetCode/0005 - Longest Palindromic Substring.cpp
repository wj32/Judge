class Solution {
public:
    string longestPalindrome(string s) {
        size_t longestLength = 0;
        size_t longestIndex = 0;
        for (size_t i = 0; i < s.size(); i++) {
            const auto update = [&](size_t bias) {
                const auto n = min(i, s.size() - i - bias);
                const auto w = [&] {
                    size_t j;
                    for (j = 0; j < n; j++) {
                        if (s[i - j - 1] != s[i + j + bias]) {
                            break;
                        }
                    }
                    return j;
                }();

                if (longestLength < w * 2 + bias) {
                    longestLength = w * 2 + bias;
                    longestIndex = i;
                }
            };

            update(0);
            update(1);
        }

        return s.substr(longestIndex - longestLength / 2, longestLength);
    }
};
