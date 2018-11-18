class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        for (int i = 31; i >= 0; i--) {
            if (((m ^ n) & (1 << i)) != 0) {
                return m & ~((1 << i) - 1);
            }
        }
        return m;
    }
};
