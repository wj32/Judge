class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int dst = 0;
        for (int src = 0; src < nums.size(); ++src) {
            if (nums[src] % 2 == 0) {
                swap(nums[dst], nums[src]);
                ++dst;
            }
        }
        return move(nums);
    }
};