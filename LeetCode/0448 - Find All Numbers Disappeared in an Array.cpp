class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 1; i <= nums.size(); i++) {
            const int x = nums[i - 1] & 0x7fffffff;
            nums[x - 1] |= 0x80000000;
        }

        vector<int> r;
        for (int i = 1; i <= nums.size(); i++) {
            if ((nums[i - 1] & 0x80000000) == 0) {
                r.push_back(i);
            }
        }
        return r;
    }
};
