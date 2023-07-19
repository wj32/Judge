class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> r;
        r.reserve(nums.size());
        int x = 0;
        for (const auto b : nums) {
            x = (x * 2 + b) % 5;
            r.push_back(x == 0);
        }
        return r;
    }
};