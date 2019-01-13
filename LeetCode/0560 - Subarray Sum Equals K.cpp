class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sums;
        sums[0] = 1;
        int count = 0;
        int sum = 0;
        for (const int x : nums) {
            sum += x;
            const auto it = sums.find(sum - k);
            if (it != sums.end()) {
                count += it->second;
            }
            sums[sum]++;
        }
        return count;
    }
};
