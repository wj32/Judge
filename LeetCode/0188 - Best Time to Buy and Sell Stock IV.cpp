class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k >= prices.size() / 2) {
            int sum = 0;
            for (int i = 1; i < prices.size(); i++) {
                sum += max(prices[i] - prices[i - 1], 0);
            }
            return sum;
        }

        vector<int> states(1 + (k * 2), 0);
        for (int j = 0; j < k; j++) {
            states[1 + (j * 2)] = numeric_limits<int>::min();
        }

        for (const int x : prices) {
            for (int j = k - 1; j >= 0; j--) {
                states[1 + (j * 2) + 1] = max(states[1 + (j * 2) + 1], states[1 + (j * 2)] + x);
                states[1 + (j * 2)] = max(states[1 + (j * 2)], states[1 + (j * 2) - 1] - x);
            }
        }

        return states.back();
    }
};
