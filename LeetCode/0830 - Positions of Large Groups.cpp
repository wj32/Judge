class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> r;
        int runLength = 1;
        for (int i = 1; i < S.size(); i++) {
            if (S[i] == S[i - 1]) {
                runLength++;
            }
            else {
                if (runLength >= 3) {
                    r.push_back({i - runLength, i - 1});
                }
                runLength = 1;
            }
        }
        if (runLength >= 3) {
            r.push_back({S.size() - runLength, S.size() - 1});
        }
        return r;
    }
};
