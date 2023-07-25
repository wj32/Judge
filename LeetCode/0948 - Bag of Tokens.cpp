class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int up = 0;
        int down = tokens.size() - 1;
        int score = 0;
        int maxScore = 0;
        while (up <= down) {
            if (power >= tokens[up]) {
                power -= tokens[up];
                ++score;
                maxScore = max(maxScore, score);
                ++up;
            } else if (score >= 1) {
                power += tokens[down];
                --score;
                --down;
            } else {
                break;
            }
        }
        return maxScore;
    }
};