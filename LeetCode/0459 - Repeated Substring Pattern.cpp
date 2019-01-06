class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for (int i = 1; i <= s.size() / 2; i++) {
            if ((s.size() % i) == 0) {
                bool match = true;
                for (int j = i; j < s.size(); j++) {
                    if (s[j] != s[j % i]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    return true;
                }
            }
        }
        return false;
    }
};
