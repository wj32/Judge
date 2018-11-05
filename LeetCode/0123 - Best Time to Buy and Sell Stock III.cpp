class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b1 = numeric_limits<int>::min();
        int s1 = 0;
        int b2 = numeric_limits<int>::min();
        int s2 = 0;
        for (const int x : prices) {
            b1 = max(b1, 0 - x);
            s1 = max(s1, b1 + x);
            b2 = max(b2, s1 - x);
            s2 = max(s2, b2 + x);
        }
        return s2;
    }
};
