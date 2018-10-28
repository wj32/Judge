class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int dst = 0;

        for (int src = 1; src < nums.size(); src++) {
            if (nums[dst] != nums[src]) {
                dst++;
                nums[dst] = nums[src];
            }
        }

        return dst + 1;
    }
};
