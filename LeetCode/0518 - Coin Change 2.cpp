class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (coins.size() == 0) {
            return (amount == 0) ? 1 : 0;
        }
        sort(coins.begin(), coins.end());
        vector<int> r(amount + 1, 0);
        for (int j = 0; j <= amount; j += coins[0]) {
            r[j] = 1;
        }
        for (int i = 1; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                r[j] += r[j - coins[i]];
            }
            if (coins[i] > amount) {
                break;
            }
        }
        return r[amount];
    }
};
