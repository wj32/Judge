class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int zero = 0;
        int prevZero = 0;
        int one = 0;
        int maxBalance = 0;
        for (const auto c : s) {
            if (c == '0') {
                maxBalance = max(maxBalance, min(prevZero, one));
                one = 0;
                ++zero;
            } else {
                if (zero != 0) {
                    prevZero = zero;
                    zero = 0;
                }
                ++one;
            }
        }
        maxBalance = max(maxBalance, min(prevZero, one));
        return maxBalance * 2;
    }
};