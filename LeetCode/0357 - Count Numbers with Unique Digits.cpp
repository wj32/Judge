class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        n--;
        int m = 9;
        int x = 9;
        int r = 10;
        while ((n != 0) && (m != 0)) {
            x *= m;
            r += x;
            m--;
            n--;
        }
        return r;
    }
};
