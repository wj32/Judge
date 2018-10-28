class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;

        const int all = (1 << nums.size()) - 1;
        for (int subset = 0; subset <= all; subset++) {
            vector<int> v;
            for (int i = 0; i < nums.size(); i++) {
                if ((subset & (1 << i)) != 0) {
                    v.push_back(nums[i]);
                }
            }
            result.push_back(v);
        }

        return result;
    }
};
