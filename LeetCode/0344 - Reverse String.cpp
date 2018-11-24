class Solution {
public:
    string reverseString(string s) {
        for (size_t i = 0; i < s.size() / 2; i++) {
            swap(s[i], s[s.size() - 1 - i]);
        }
        return s;
    }
};
