class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int o = 0;
        int x = 0;
        for (const auto& row : board) {
            for (const char c : row) {
                if (c == 'O') {
                    o++;
                }
                else if (c == 'X') {
                    x++;
                }
            }
        }

        if ((o > x) || (x > o + 1)) {
            return false;
        }

        const vector<array<int, 6>> winPositions{
            {0, 0, 0, 1, 0, 2},
            {0, 0, 1, 0, 2, 0},
            {1, 0, 1, 1, 1, 2},
            {0, 1, 1, 1, 2, 1},
            {2, 0, 2, 1, 2, 2},
            {0, 2, 1, 2, 2, 2},
            {0, 0, 1, 1, 2, 2},
            {0, 2, 1, 1, 2, 0}
        };

        const auto isWin = [&](const array<int, 6>& i) {
            return ((board[i[0]][i[1]] == 'O') && (board[i[2]][i[3]] == 'O') && (board[i[4]][i[5]] == 'O')) ||
                   ((board[i[0]][i[1]] == 'X') && (board[i[2]][i[3]] == 'X') && (board[i[4]][i[5]] == 'X'));
        };

        for (const auto& position : winPositions) {
            if (isWin(position)) {
                bool canLose = false;

                for (int i = 0; i < 3; i++) {
                    auto& cell = board[position[i * 2]][position[(i * 2) + 1]];
                    char c = ' ';
                    swap(cell, c);
                    bool canWin = false;
                    for (const auto& nestedPosition : winPositions) {
                        if (isWin(nestedPosition)) {
                            canWin = true;
                            break;
                        }
                    }
                    swap(cell, c);
                    if (!canWin) {
                        canLose = true;
                        break;
                    }
                }

                if (!canLose) {
                    return false;
                }

                if (board[position[0]][position[1]] == 'X') {
                    if (x != o + 1) {
                        return false;
                    }
                }
                else {
                    if (x != o) {
                        return false;
                    }
                }

                break;
            }
        }

        return true;
    }
};
