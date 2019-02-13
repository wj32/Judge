class Solution {
public:
    int binaryGap(int N) {
        int maxDistance = 0;
        int lastIndex = 32;
        for (int i = 0; i < 31; i++) {
            if ((N & (1 << i)) != 0) {
                maxDistance = max(maxDistance, i - lastIndex);
                lastIndex = i;
            }
        }
        return maxDistance;
    }
};
