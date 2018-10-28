class Solution {
public:
    string longestPalindrome(string s) {
        size_t longestLength = 0;
        size_t longestIndex = 0;
        for (size_t i = 0; i < s.size(); i++) {
            size_t m = min(i, s.size() - 1 - i);
            size_t j;
            for (j = 0; j < m; j++) {
                if (s[i - j - 1] != s[i + j + 1]) {
                    break;
                }
            }

            if (longestLength < j * 2 + 1) {
                longestLength = j * 2 + 1;
                longestIndex = i;
            }

            size_t n = min(i, s.size() - 1);
            size_t k;
            for (k = 0; k < n; k++) {
                if (s[i + k] != s[i - k - 1]) {
                    break;
                }
            }

            if (longestLength < k * 2) {
                longestLength = k * 2;
                longestIndex = i;
            }
        }

        return s.substr(longestIndex - longestLength / 2, longestLength);
    }
};
