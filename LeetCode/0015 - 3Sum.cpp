class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> solutions;

        for (int i = 0; i < nums.size(); i++) {
            if ((i > 0) && (nums[i] == nums[i - 1])) {
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                if ((j > i + 1) && (nums[j] == nums[j - 1])) {
                    j++;
                    continue;
                }
                if ((k < nums.size() - 1) && (nums[k] == nums[k + 1])) {
                    k--;
                    continue;
                }
                if (nums[j] + nums[k] < -nums[i]) {
                    j++;
                }
                else if (nums[j] + nums[k] > -nums[i]) {
                    k--;
                } else {
                    solutions.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
            }
        }

        return solutions;
    }
};
