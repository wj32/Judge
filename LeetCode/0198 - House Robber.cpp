class Solution {
public:
    int rob(vector<int>& nums) {
        int x = 0;
        int y = 0;
        for (const int m : nums) {
            const int z = max(x + m, y);
            x = y;
            y = z;
        }
        return y;
    }
};
