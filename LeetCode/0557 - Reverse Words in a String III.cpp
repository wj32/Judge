class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while ((j < s.size()) && !isspace(s[j])) {
                j++;
            }
            reverse(s.begin() + i, s.begin() + j);
            i = j + 1;
        }
        return s;
    }
};
