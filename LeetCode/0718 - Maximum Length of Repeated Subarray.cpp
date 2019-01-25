class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int>> r(A.size() + 1, vector<int>(B.size() + 1));
        int m = 0;

        for (int j = 0; j <= B.size(); j++) {
            r[0][j] = 0;
        }
        for (int i = 1; i <= A.size(); i++) {
            r[i][0] = 0;
        }

        for (int i = 1; i <= A.size(); i++) {
            for (int j = 1; j <= B.size(); j++) {
                if (A[i - 1] == B[j - 1]) {
                    r[i][j] = r[i - 1][j - 1] + 1;
                    m = max(m, r[i][j]);
                }
                else {
                    r[i][j] = 0;
                }
            }
        }

        return m;
    }
};
