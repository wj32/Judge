class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int, int>> s;
        int low = numeric_limits<int>::max();
        int high = numeric_limits<int>::min();

        for (const int x : nums) {
            if (x > low) {
                if (x < high) {
                    return true;
                }
                else if (x > high) {
                    high = x;
                    while (!s.empty() && (high > s.top().first)) {
                        if (high < s.top().second) {
                            return true;
                        }
                        s.pop();
                    }
                }
            }
            else {
                if (low < high) {
                    s.push({low, high});
                }
                low = x;
                high = numeric_limits<int>::min();
            }
        }

        return false;
    }
};
