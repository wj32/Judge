class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<short>> rightDown(N, vector<short>(N, 1));
        for (const auto& p : mines) {
            rightDown[p[0]][p[1]] = 0;
        }

        vector<short> down(N, 0);
        for (int i = N - 1; i >= 0; i--) {
            short right = 0;
            for (int j = N - 1; j >= 0; j--) {
                if (rightDown[i][j] != 0) {
                    right++;
                    down[j]++;
                    rightDown[i][j] = min(right, down[j]);
                }
                else {
                    right = 0;
                    down[j] = 0;
                }
            }
        }

        vector<short> up(N, 0);
        short maxOrder = 0;
        for (int i = 0; i < N; i++) {
            short left = 0;
            for (int j = 0; j < N; j++) {
                if (rightDown[i][j] != 0) {
                    left++;
                    up[j]++;
                    maxOrder = max(maxOrder, min(left, min(up[j], rightDown[i][j])));
                }
                else {
                    left = 0;
                    up[j] = 0;
                }
            }
        }
        return maxOrder;
    }
};
