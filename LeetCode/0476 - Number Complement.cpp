class Solution {
public:
    int findComplement(int num) {
        int x = num;
        while (true) {
            const int y = x & (x - 1);
            if (y == 0) {
                break;
            }
            x = y;
        }
        return ~num & (x - 1);
    }
};
