class Solution {
public:
    int gcd(int x, int y) {
        while (y != 0) {
            const int t = y;
            y = x % y;
            x = t;
        }
        return x;
    }

    bool canMeasureWater(int x, int y, int z) {
        if (z == 0) {
            return true;
        }
        if (x + y < z) {
            return false;
        }
        if ((x == 0) || (y == 0)) {
            return x + y == z;
        }
        return (z % gcd(x, y)) == 0;
    }
};
