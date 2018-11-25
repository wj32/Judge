class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const auto infinity = numeric_limits<int>::max() / 2;

        sort(coins.begin(), coins.end());

        vector<int> r(amount + 1);
        r[0] = 0;

        for (int i = 1; i <= amount; i++) {
            int minimum = infinity;
            for (const auto coin : coins) {
                if (coin > i) {
                    break;
                }
                minimum = min(minimum, r[i - coin]);
            }
            r[i] = minimum + 1;
        }

        return (r[amount] < infinity) ? r[amount] : -1;
    }
};
