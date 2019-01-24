class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int b = 1;
        for (int i = 0; i < bits.size(); ) {
            b = bits[i] + 1;
            i += b;
        }
        return b == 1;
    }
};
