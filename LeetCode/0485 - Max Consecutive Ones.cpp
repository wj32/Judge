class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxRun = 0;
        int run = 0;
        for (const int x : nums) {
            if (x == 1) {
                run++;
            }
            else {
                maxRun = max(maxRun, run);
                run = 0;
            }
        }
        maxRun = max(maxRun, run);
        return maxRun;
    }
};
