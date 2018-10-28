class Solution {
public:
    int climbStairs(int n) {
        int x = 0;
        int y = 1;

        while (n != 0) {
            const int z = x + y;
            x = y;
            y = z;
            n--;
        }

        return y;
    }
};
