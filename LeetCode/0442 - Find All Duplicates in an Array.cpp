class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> r;
        for (int i = 1; i <= nums.size(); i++) {
            const int x = nums[i - 1] & 0x7fffffff;
            if ((nums[x - 1] & 0x80000000) != 0) {
                r.push_back(x);
            }
            else {
                nums[x - 1] |= 0x80000000;
            }
        }
        return r;
    }
};
