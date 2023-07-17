class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> r(text2.size() + 1, 0);
        vector<int> s(text2.size() + 1);
        for (size_t i = 1; i <= text1.size(); ++i) {
            s[0] = 0;
            for (size_t j = 1; j <= text2.size(); ++j) {
                s[j] = text1[i - 1] == text2[j - 1] ? r[j - 1] + 1 : max(r[j], s[j - 1]);
            }
            swap(r, s);
        }
        return r[text2.size()];
    }
};