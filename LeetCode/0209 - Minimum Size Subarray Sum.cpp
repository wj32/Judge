class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int i = 0;
        int j = 0;
        int sum = 0;
        int minLength = numeric_limits<int>::max();

        while (true) {
            while (sum < s) {
                j++;
                if (j > nums.size()) {
                    break;
                }
                sum += nums[j - 1];
            }
            if (j > nums.size()) {
                break;
            }
            if (minLength > j - i) {
                minLength = j - i;
            }

            sum -= nums[j - 1];
            j--;

            if (i == j) {
                i++;
                j++;
            }
            else {
                sum -= nums[i];
                i++;
            }
        }

        if (minLength != numeric_limits<int>::max()) {
            return minLength;
        }
        else {
            return 0;
        }
    }
};
