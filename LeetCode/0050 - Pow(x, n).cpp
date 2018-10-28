class Solution {
public:
    double myPow(double x, int n) {
        if (n == -n) { // for -2^31
            return 1 / myPow(x, n - 1) / x;
        }
        else if (n < 0) {
            return 1 / myPow(x, -n);
        }
        else if (n == 0) {
            return 1;
        }
        else {
            double r = 1;

            while (n != 0) {
                if ((n % 2) == 0) {
                    x *= x;
                    n /= 2;
                }
                else {
                    r *= x;
                    n--;
                }
            }

            return r;
        }
    }
};
