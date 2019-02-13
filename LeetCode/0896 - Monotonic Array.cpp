class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool increasing = true;
        bool decreasing = true;
        for (int i = 1; i < A.size(); i++) {
            if (A[i - 1] < A[i]) {
                decreasing = false;
                if (!increasing) {
                    return false;
                }
            }
            else if (A[i - 1] > A[i]) {
                increasing = false;
                if (!decreasing) {
                    return false;
                }
            }
        }
        return true;
    }
};
