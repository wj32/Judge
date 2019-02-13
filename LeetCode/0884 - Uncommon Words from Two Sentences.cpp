class Solution {
public:
    template<typename Func>
    void forEachWord(const string& s, Func f) {
        size_t i = 0;
        while (i < s.size()) {
            size_t j = i + 1;
            while ((j < s.size()) && isalpha(s[j])) {
                j++;
            }
            f(s.substr(i, j - i));
            i = j + 1;
        }
    }

    vector<string> uncommonFromSentences(string A, string B) {
        map<string, int> m;
        forEachWord(A, [&](const string& word) {
            m[word]++;
        });
        forEachWord(B, [&](const string& word) {
            m[word]++;
        });

        vector<string> r;
        for (const auto& p : m) {
            if (p.second == 1) {
                r.push_back(p.first);
            }
        }
        return r;
    }
};
