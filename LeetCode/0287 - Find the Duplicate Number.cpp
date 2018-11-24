class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while (slow != fast);
        int index = 0;
        while (index != slow) {
            index = nums[index];
            slow = nums[slow];
        }
        return index;
    }
};
