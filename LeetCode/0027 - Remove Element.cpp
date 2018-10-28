class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int dst = 0;

        for (int src = 0; src < nums.size(); src++) {
            if (nums[src] != val) {
                nums[dst] = nums[src];
                dst++;
            }
        }

        return dst;
    }
};
