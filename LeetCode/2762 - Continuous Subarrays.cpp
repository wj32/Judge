class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long r = 0;
        map<int, int> m;
        int i = 0;
        for (int j = 0; j < nums.size(); ++j) {
            ++m[nums[j]];
            while (m.begin()->first < nums[j] - 2 ||
                   m.rbegin()->first > nums[j] + 2) {
                const auto it = m.find(nums[i]);
                assert(it != m.end());
                if (--it->second == 0) {
                    m.erase(it);
                }
                ++i;
            }
            r += j - i + 1;
        }
        return r;
    }
};