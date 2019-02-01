class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int maxMidRunLength = 0;
        int firstRunLength = -1;
        int lastRunLength = 0;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 1) {
                if (firstRunLength == -1) {
                    firstRunLength = lastRunLength;
                }
                else {
                    maxMidRunLength = max(maxMidRunLength, lastRunLength);
                }
                lastRunLength = 0;
            }
            else {
                lastRunLength++;
            }
        }
        return max(max((maxMidRunLength + 1) / 2, firstRunLength), lastRunLength);
    }
};
