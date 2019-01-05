class Solution {
public:
    string frequencySort(string s) {
        array<pair<int, char>, 256> a{};
        for (const char c : s) {
            const auto p = &a[static_cast<unsigned char>(c)];
            p->first--;
            p->second = c;
        }
        sort(a.begin(), a.end());
        string t;
        t.reserve(s.size());
        for (const auto& p : a) {
            if (p.first == 0) {
                break;
            }
            t.append(-p.first, p.second);
        }
        return t;
    }
};
