class Solution {
public:
    int mySqrt(int x) {
        long low = 0;
        long high = std::min(std::max(x / 2, 1), 46340);
        while (low < high) {
            const auto mid = low + (high - low + 1) / 2;
            if (x < mid * mid) {
                high = mid - 1;
            } else {
                low = mid;
            }
        }
        return low;
    }
};