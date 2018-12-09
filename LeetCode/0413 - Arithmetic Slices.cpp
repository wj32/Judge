class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int runCount = 2;
        int sum = 0;
        for (int i = 1; i < A.size(); i++) {
            if ((i + 1 < A.size()) && (A[i] - A[i - 1] == A[i + 1] - A[i])) {
                runCount++;
            }
            else {
                if (runCount >= 3) {
                    sum += (runCount - 1) * (runCount - 2) / 2;
                }
                runCount = 2;
            }
        }
        return sum;
    }
};
