class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int currentProfit = 0;
        for (int i = 1; i < prices.size(); i++) {
            const auto d = prices[i] - prices[i - 1];
            currentProfit = max(currentProfit + d, 0);
            maxProfit = max(maxProfit, currentProfit);
        }
        return maxProfit;
    }
};
