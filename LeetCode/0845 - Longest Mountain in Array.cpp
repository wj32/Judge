class Solution {
public:
    int longestMountain(vector<int>& A) {
        int upLength = 0;
        int downLength = 0;
        int maxTotalLength = 0;
        for (int i = 1; i < A.size(); i++) {
            if (A[i - 1] < A[i]) {
                if (downLength == 0) {
                    upLength++;
                }
                else {
                    upLength = 1;
                    downLength = 0;
                }
            }
            else if (A[i - 1] > A[i]) {
                if (upLength != 0) {
                    downLength++;
                    maxTotalLength = max(maxTotalLength, upLength + downLength + 1);
                }
            }
            else {
                upLength = 0;
                downLength = 0;
            }
        }
        return maxTotalLength;
    }
};
