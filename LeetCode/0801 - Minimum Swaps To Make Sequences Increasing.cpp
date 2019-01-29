class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        const int n = A.size();
        int x1 = 0; // No swap
        int y1 = 1; // Swap
        for (int i = 1; i < n; i++) {
            int x0 = n;
            int y0 = n;
            if ((A[i - 1] < A[i]) && (B[i - 1] < B[i])) {
                x0 = min(x0, x1);
                y0 = min(y0, y1 + 1);
            }
            if ((A[i - 1] < B[i]) && (B[i - 1] < A[i])) {
                x0 = min(x0, y1);
                y0 = min(y0, x1 + 1);
            }
            x1 = x0;
            y1 = y0;
        }
        return min(x1, y1);
    }
};
