class Solution {
public:
    int reachNumber(int target) {
        if (target < 0) {
            target = -target;
        }
        int n = 0;
        while (target > 0) {
            n++;
            target -= n;
        }
        if ((target % 2) == 0) {
            return n;
        }
        else {
            return n + (n % 2) + 1;
        }
    }
};
