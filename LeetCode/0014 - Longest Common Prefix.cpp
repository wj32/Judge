class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        for (size_t i = 0; ; ++i) {
            char c = i < strs[0].size() ? strs[0][i] : '\0';
            for (const auto& s : strs) {
                if (i >= s.size() || s[i] != c) {
                    c = '\0';
                    break;
                }
            }
            if (c == '\0') {
                break;
            }
            result += c;
        }
        return result;
    }
};