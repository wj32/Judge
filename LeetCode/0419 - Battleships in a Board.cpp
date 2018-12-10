class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.size() == 0) {
            return 0;
        }
        const auto m = board.size();
        const auto n = board[0].size();
        const auto get = [&](int i, int j) {
            if ((i >= 0) && (i < m) && (j >= 0) && (j < n)) {
                return board[i][j] == 'X';
            }
            else {
                return false;
            }
        };

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (get(i, j) && !get(i - 1, j) && !get(i, j - 1)) {
                    count++;
                }
            }
        }
        return count;
    }
};
