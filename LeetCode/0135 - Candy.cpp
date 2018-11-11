class Solution {
public:
    int candy(vector<int>& ratings) {
        const auto n = ratings.size();
        vector<int> c(n, 1);

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                c[i] = max(c[i], c[i - 1] + 1);
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                c[i] = max(c[i], c[i + 1] + 1);
            }
        }

        return accumulate(c.begin(), c.end(), 0);
    }
};
