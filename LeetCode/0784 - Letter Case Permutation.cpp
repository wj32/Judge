class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<int> indices;
        for (int i = 0; i < S.size(); i++) {
            if (isalpha(S[i])) {
                indices.push_back(i);
            }
        }

        const int limit = (1 << indices.size()) - 1;
        vector<string> r;
        for (int bits = 0; bits <= limit; bits++) {
            for (int i = 0; i < indices.size(); i++) {
                S[indices[i]] = ((bits & (1 << i)) != 0) ? toupper(S[indices[i]]) : tolower(S[indices[i]]);
            }
            r.push_back(S);
        }
        return r;
    }
};
