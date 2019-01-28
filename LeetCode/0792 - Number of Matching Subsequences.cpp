class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        array<vector<int>, 26> a;
        for (int i = 0; i < S.size(); i++) {
            a[S[i] - 'a'].push_back(i);
        }

        int count = 0;
        array<int, 26> positions;

        for (const auto& word : words) {
            positions = {};

            bool subsequence = true;
            int index = 0;

            for (const char c : word) {
                const auto& v = a[c - 'a'];
                const auto it = lower_bound(v.begin() + positions[c - 'a'], v.end(), index);
                if (it == v.end()) {
                    subsequence = false;
                    break;
                }
                positions[c - 'a'] = it - v.begin() + 1;
                index = *it + 1;
            }

            if (subsequence) {
                count++;
            }
        }

        return count;
    }
};
