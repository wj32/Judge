class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int deletions = 0;
        vector<bool> tie(strs.size() - 1, true);
        size_t tieCount = tie.size();
        for (size_t j = 0; j < strs[0].size() && tieCount != 0; ++j) {
            auto newTie = tie;
            auto newTieCount = tieCount;
            bool deletion = false;
            for (size_t i = 1; i < strs.size(); ++i) {
                if (!newTie[i - 1]) {
                    continue;
                }
                if (strs[i - 1][j] < strs[i][j]) {
                    newTie[i - 1] = false;
                    --newTieCount;
                } else if (strs[i - 1][j] > strs[i][j]) {
                    deletion = true;
                    break;
                }
            }
            if (deletion) {
                ++deletions;
                continue;
            }
            tie = newTie;
            tieCount = newTieCount;
        }
        return deletions;
    }
};