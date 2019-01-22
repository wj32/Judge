class Solution {
public:
    bool recurse(const string& s, int i, int j, bool deleted) {
        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            }
            else {
                if (deleted) {
                    return false;
                }
                return recurse(s, i + 1, j, true) || recurse(s, i, j - 1, true);
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        return recurse(s, 0, s.size() - 1, false);
    }
};
