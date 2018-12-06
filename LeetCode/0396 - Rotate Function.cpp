class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        const int n = static_cast<int>(A.size());
        int f = 0;
        int s = 0;
        for (int i = 0; i < n; i++) {
            f += i * A[i];
            s += A[i];
        }

        int maxF = f;
        for (int i = 1; i < n; i++) {
            f = f - (A[n - i] * n) + s;
            maxF = max(maxF, f);
        }
        return maxF;
    }
};
