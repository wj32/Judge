class Solution {
public:
    bool hasAlternatingBits(int n) {
        int mask = n;
        mask |= mask >> 1;
        mask |= mask >> 2;
        mask |= mask >> 4;
        mask |= mask >> 8;
        mask |= mask >> 16;
        return (((n ^ 0x55555555) & mask) == 0) || (((n ^ 0xaaaaaaaa) & mask) == 0);
    }
};
