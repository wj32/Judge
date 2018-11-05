class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int maxRun = 0;
        for (const int x : nums) {
            if (s.find(x - 1) == s.end()) {
                int run = 1;
                for (int y = x + 1; s.find(y) != s.end(); y++) {
                    run++;
                }
                maxRun = max(maxRun, run);
            }
        }
        return maxRun;
    }
};
