class Solution {
public:
    int getSum(int a, int b) {
        const auto v = {a, b};
        return accumulate(v.begin(), v.end(), 0);
    }
};
