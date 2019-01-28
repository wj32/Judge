class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        vector<int> s;
        s.reserve(A.size());

        vector<int> ngeRight(A.size());
        for (int i = A.size() - 1; i >= 0; i--) {
            while (!s.empty() && (A[s.back()] <= A[i])) {
                s.pop_back();
            }
            ngeRight[i] = s.empty() ? A.size() : s.back();
            s.push_back(i);
        }

        s.clear();

        int count = 0;

        for (int i = 0; i < A.size(); i++) {
            while (!s.empty() && (A[s.back()] < A[i])) { // Asymmetric to handle duplicates
                s.pop_back();
            }
            const int ngeLeft = s.empty() ? -1 : s.back();
            if (!s.empty() && (A[s.back()] == A[i])) {
                s.back() = i;
            }
            else {
                s.push_back(i);
            }

            if ((A[i] >= L) && (A[i] <= R)) {
                count += (i - ngeLeft) * (ngeRight[i] - i);
            }
        }

        return count;
    }
};
