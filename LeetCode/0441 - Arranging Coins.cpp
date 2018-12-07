class Solution {
public:
    int arrangeCoins(int n) {
        // r(r+1)/2 = n
        // r^2+r-2n = 0
        return static_cast<int>((sqrt((static_cast<double>(n) * 8) + 1) - 1) / 2);
    }
};
