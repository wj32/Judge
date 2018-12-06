class Solution {
public:
    int thirdMax(vector<int>& nums) {
        const auto minimum = numeric_limits<long long>::min();
        auto c = minimum;
        auto b = minimum;
        auto a = minimum;

        for (const int x : nums) {
            if (c < x) {
                a = b;
                b = c;
                c = x;
            }
            else if (c > x) {
                if (b < x) {
                    a = b;
                    b = x;
                }
                else if (b > x) {
                    if (a < x) {
                        a = x;
                    }
                }
            }
        }

        return static_cast<int>((a != minimum) ? a : c);
    }
};
