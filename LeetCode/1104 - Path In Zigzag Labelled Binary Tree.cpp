class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int exponent = 0;
        int bound = 1;
        for (; bound <= label; bound *= 2, ++exponent) {
        }
        const auto reflect = [&](const auto x) {
            return bound / 2 + (bound - x) - 1;
        };
        if (exponent % 2 == 0) {
            label = reflect(label);
        }
        vector<int> r;
        for (; label != 0; label /= 2, bound /= 2, --exponent) {
            r.push_back(exponent % 2 == 0 ? reflect(label) : label);
        }
        reverse(r.begin(), r.end());
        return r;
    }
};