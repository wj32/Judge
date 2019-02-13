class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        const auto sortAlternating = [&](const string& s) {
            string t;
            t.reserve(s.size());
            for (int i = 0; i < s.size(); i += 2) {
                t.append(1, s[i]);
            }
            for (int i = 1; i < s.size(); i += 2) {
                t.append(1, s[i]);
            }
            const auto mid = t.begin() + ((t.size() + 1) / 2);
            sort(t.begin(), mid);
            sort(mid, t.end());
            return t;
        };

        set<string> unique;
        for (const auto& s : A) {
            unique.insert(sortAlternating(s));
        }
        return unique.size();
    }
};
