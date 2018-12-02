// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;
        while (low <= high) {
            const int mid = low + (high - low) / 2;
            switch (guess(mid)) {
            case 0:
                return mid;
            case -1:
                high = mid - 1;
                break;
            case 1:
                low = mid + 1;
                break;
            }
        }
    }
};
