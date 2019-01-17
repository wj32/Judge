class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size();

        while (true) {
            assert(left < right);
            int midLeft = left + (right - left) / 2;
            int midRight = midLeft + 1;
            if ((midLeft - 1 >= left) && (nums[midLeft - 1] == nums[midLeft])) {
                midLeft--;
            }
            else if ((midRight < right) && (nums[midRight] == nums[midLeft])) {
                midRight++;
            }

            if (midRight - midLeft == 1) {
                return nums[midLeft];
            }

            if (((midLeft - left) % 2) != 0) {
                right = midLeft;
            }
            else {
                left = midRight;
            }
        }
    }
};
