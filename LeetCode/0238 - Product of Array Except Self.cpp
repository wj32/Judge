class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> r(nums.size());
        int product;

        product = 1;
        for (int i = 0; i < nums.size(); i++) {
            r[i] = product;
            product *= nums[i];
        }

        product = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            r[i] *= product;
            product *= nums[i];
        }

        return r;
    }
};
