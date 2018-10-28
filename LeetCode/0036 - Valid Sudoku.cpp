class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            array<bool, 9> a{};
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    const int d = board[i][j] - '1';
                    if (a[d]) {
                        return false;
                    }
                    a[d] = true;
                }
            }
        }
        for (int j = 0; j < 9; j++) {
            array<bool, 9> a{};
            for (int i = 0; i < 9; i++) {
                if (board[i][j] != '.') {
                    const int d = board[i][j] - '1';
                    if (a[d]) {
                        return false;
                    }
                    a[d] = true;
                }
            }
        }
        for (int m = 0; m < 9; m += 3) {
            for (int n = 0; n < 9; n += 3) {
                array<bool, 9> a{};
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (board[m + i][n + j] != '.') {
                            const int d = board[m + i][n + j] - '1';
                            if (a[d]) {
                                return false;
                            }
                            a[d] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};
