class Solution {
public:
    int clumsy(int n) {
        int result = 0;
        int sign = 1;
        for (int i = n; i >= 1; i -= 4) {
            int t = i;
            if (i >= 2) {
                t *= i - 1;
            }
            if (i >= 3) {
                t /= i - 2;
            }
            result += sign * t;
            sign = -1;
            if (i >= 4) {
                result += i - 3;
            }
        }
        return result;
    }
};