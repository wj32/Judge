class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> r(S.size());
        int lastIndex;

        lastIndex = -static_cast<int>(S.size());
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == C) {
                lastIndex = i;
            }
            r[i] = i - lastIndex;
        }

        lastIndex = S.size() * 2;
        for (int i = S.size() - 1; i >= 0; i--) {
            if (S[i] == C) {
                lastIndex = i;
            }
            r[i] = min(r[i], lastIndex - i);
        }

        return r;
    }
};
