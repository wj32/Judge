class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int dst = 0;
        int count = 1;

        for (int src = 1; src < nums.size(); src++) {
            if (nums[dst] != nums[src]) {
                count = 0;
            }
            if (count < 2) {
                dst++;
                nums[dst] = nums[src];
                count++;
            }
        }

        return dst + 1;
    }
};
