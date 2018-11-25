class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b = numeric_limits<int>::min();
        int s = 0;
        int c = 0;
        for (const int x : prices) {
            const auto co = c;
            c = max(c, s);
            s = max(s, b + x);
            b = max(b, co - x);
        }
        return s;
    }
};
