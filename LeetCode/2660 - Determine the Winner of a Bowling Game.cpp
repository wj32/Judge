class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        const auto getScore = [&](const auto& v) {
            int score = 0;
            for (size_t i = 0; i < v.size(); ++i) {
                score += v[i] * (((i >= 1 && v[i - 1] == 10) || (i >= 2 && v[i - 2] == 10)) ? 2 : 1);
            }
            return score;
        };
        const auto score1 = getScore(player1);
        const auto score2 = getScore(player2);
        return score1 > score2 ? 1 : score1 < score2 ? 2 : 0;
    }
};