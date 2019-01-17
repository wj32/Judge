class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), [&](const auto& a, const auto& b) {
            if (a.size() != b.size()) {
                return a.size() > b.size();
            }
            return a < b;
        });

        array<set<int>, 26> indicesByChar;
        for (int i = 0; i < s.size(); i++) {
            indicesByChar[s[i] - 'a'].insert(i);
        }

        size_t maxSize = 0;
        const string* maxSizeString = nullptr;

        for (const auto& t : d) {
            if (t.size() < maxSize) {
                break;
            }

            bool match = true;
            int i = 0;
            for (const char c : t) {
                const auto& indices = indicesByChar[c - 'a'];
                const auto it = indices.lower_bound(i);
                if (it == indices.end()) {
                    match = false;
                    break;
                }
                i = *it + 1;
            }

            if (match && (maxSize < t.size())) {
                maxSize = t.size();
                maxSizeString = &t;
            }
        }

        return (maxSizeString != nullptr) ? *maxSizeString : "";
    }
};
