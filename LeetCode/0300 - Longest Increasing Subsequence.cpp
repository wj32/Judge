class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> a;
        for (const int x : nums) {
            const auto it = lower_bound(a.begin(), a.end(), x);
            if (it != a.end()) {
                *it = x;
            }
            else {
                a.push_back(x);
            }
        }
        return a.size();
    }
};
