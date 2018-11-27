class Solution {
public:
    bool isPerfectSquare(int num) {
        long long low = 1;
        long long high = (num + 1) / 2;
        while (low <= high) {
            const auto mid = low + (high - low) / 2;
            const auto mid2 = mid * mid;
            if (mid2 < num) {
                low = mid + 1;
            }
            else if (mid2 > num) {
                high = mid - 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};
