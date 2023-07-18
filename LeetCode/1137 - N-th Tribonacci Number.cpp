class Solution {
public:
    int tribonacci(int n) {
        if (n < 2) {
            return n;
        }
        int x = 0;
        int y = 1;
        int z = 1;
        for (; n > 2; --n) {
            const auto w = x + y + z;
            x = y;
            y = z;
            z = w;
        }
        return z;
    }
};