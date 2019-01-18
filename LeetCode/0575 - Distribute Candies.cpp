class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        sort(candies.begin(), candies.end());
        int halfSize = candies.size() / 2;
        int distinct = 1;
        if (distinct == halfSize) {
            return distinct;
        }
        for (int i = 1; i < candies.size(); i++) {
            if (candies[i - 1] != candies[i]) {
                distinct++;
                if (distinct == halfSize) {
                    break;
                }
            }
        }
        return distinct;
    }
};
