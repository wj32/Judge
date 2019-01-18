class Solution {
public:
    bool judgeSquareSum(int c) {
        int limit = static_cast<int>(sqrt(c) + 0.5);
        for (int a = 0; a <= limit; a++) {
            const auto b2 = c - (a * a);
            const auto br = static_cast<int>(sqrt(b2));
            if (b2 == br * br) {
                return true;
            }
        }
        return false;
    }
};
