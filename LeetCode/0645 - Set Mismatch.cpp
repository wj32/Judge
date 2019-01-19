class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        const int highBit = static_cast<int>(0x80000000);
        int duplicate = -1;
        int remaining = nums.size() * (nums.size() + 1) / 2;
        for (int i = 0; i < nums.size(); i++) {
            const int x = nums[i] & (highBit - 1);
            if ((nums[x - 1] & highBit) != 0) {
                duplicate = x;
            }
            else {
                nums[x - 1] |= highBit;
                remaining -= x;
            }
        }
        return {duplicate, remaining};
    }
};
