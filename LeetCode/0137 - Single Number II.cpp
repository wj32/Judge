class Solution {
public:
    int singleNumber(vector<int>& nums) {
        array<unsigned char, 32> b{};
        for (const int x : nums) {
            for (int i = 0; i < 32; i++) {
                b[i] = (b[i] + ((x >> i) & 1)) % 3;
            }
        }
        int y = 0;
        for (int i = 0; i < 32; i++) {
            y += static_cast<int>(b[i]) << i;
        }
        return y;
    }
};
