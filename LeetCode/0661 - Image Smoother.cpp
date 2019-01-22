class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        if (M.empty()) {
            return {};
        }
        const int m = M.size();
        const int n = M[0].size();
        vector<vector<int>> r(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0;
                int count = 0;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        const int ni = i + di;
                        const int nj = j + dj;
                        if ((ni >= 0) && (ni < m) && (nj >= 0) && (nj < n)) {
                            sum += M[ni][nj];
                            count++;
                        }
                    }
                }
                r[i][j] = sum / count;
            }
        }
        return r;
    }
};
