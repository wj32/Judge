class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int b = numeric_limits<int>::min() + 50000;
        int s = 0;
        for (const int x : prices) {
            const auto so = s;
            s = max(s, b + x - fee);
            b = max(b, so - x);
        }
        return s;
    }
};
