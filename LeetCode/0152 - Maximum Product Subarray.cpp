class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int positive = 0;
        int negative = 0;
        int maximum = numeric_limits<int>::min();

        for (const int x : nums) {
            if (x > 0) {
                positive = max(positive * x, x);
                negative = negative * x;
            }
            else if (x < 0) {
                positive = min(positive * x, x);
                negative = negative * x;
                swap(positive, negative);
            }
            else {
                positive = 0;
                negative = 0;
                maximum = max(maximum, 0);
            }

            if (positive != 0) {
                maximum = max(maximum, positive);
            }
            if (negative != 0) {
                maximum = max(maximum, negative);
            }
        }

        return maximum;
    }
};
