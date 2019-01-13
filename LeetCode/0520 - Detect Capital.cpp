class Solution {
public:
    bool detectCapitalUse(string word) {
        int mask = 0x3;
        for (int i = 1; i < word.size(); i++) {
            mask &= (word[i] <= 'Z') ? 0x1 : 0x2;
            if (mask == 0) {
                return false;
            }
        }
        return (mask & ((word[0] <= 'Z') ? 0x3 : 0x2)) != 0;
    }
};
