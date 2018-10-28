class Solution {
public:
    int lengthOfLastWord(string s) {
        int a = 0;
        int k = 0;

        for (const auto c : s) {
            if (c != ' ') {
                k++;
                a = k;
            }
            else {
                k = 0;
            }
        }

        return a;
    }
};
