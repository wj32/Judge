class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int x = 0;
        unordered_set<int> ones;
        for (int bit = 31; bit >= 0; bit--) {
            const int mask = ~((1 << (bit + 1)) - 1);
            for (const int y : nums) {
                if ((y & (1 << bit)) != 0) {
                    ones.insert(y & mask);
                }
            }
            for (const int y : nums) {
                if ((y & (1 << bit)) == 0) {
                    if (ones.find((y ^ x) & mask) != ones.end()) {
                        x |= 1 << bit;
                        break;
                    }
                }
            }
            ones.clear();
        }
        return x;
    }
};
