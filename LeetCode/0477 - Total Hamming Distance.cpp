class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total = 0;
        for (int i = 0; i < 30; i++) {
            const int mask = 1 << i;
            int count = 0;
            for (const int x : nums) {
                if ((x & mask) != 0) {
                    count++;
                }
            }
            total += count * (nums.size() - count);
        }
        return total;
    }
};
