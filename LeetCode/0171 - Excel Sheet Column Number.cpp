class Solution {
public:
    int titleToNumber(string s) {
        int n = 0;

        for (const char c : s) {
            n *= 26;
            n += c - 'A' + 1;
        }

        return n;
    }
};
