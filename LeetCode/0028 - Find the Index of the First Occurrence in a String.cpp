class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size()) {
            return -1;
        }
        for (int i = 0; i < haystack.size() - needle.size() + 1; ++i) {
            bool ok = true;
            for (int j = 0; j < needle.size(); ++j) {
                if (haystack[i + j] != needle[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                return i;
            }
        }
        return -1;
    }
};