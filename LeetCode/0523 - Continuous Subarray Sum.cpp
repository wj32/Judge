class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) {
            return false;
        }

        if (k < 0) {
            k = -k;
        }

        if (k == 0) {
            for (int i = 1; i < nums.size(); i++) {
                if ((nums[i - 1] == 0) && (nums[i] == 0)) {
                    return true;
                }
            }
            return false;
        }
        else if (k == 1) {
            return true;
        }

        unordered_set<int> s;
        s.insert(0);
        int prevSum = nums[0] % k;
        for (int i = 1; i < nums.size(); i++) {
            const int sum = (prevSum + nums[i]) % k;
            if (s.find(sum % k) != s.end()) {
                return true;
            }
            s.insert(prevSum);
            prevSum = sum;
        }
        return false;
    }
};
