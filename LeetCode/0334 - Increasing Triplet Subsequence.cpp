class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = numeric_limits<int>::max();
        int b = numeric_limits<int>::max();

        for (const int x : nums) {
            if (x > b) {
                return true;
            }
            if (x > a) {
                b = min(b, x);
            }
            a = min(a, x);
        }

        return false;
    }
};
