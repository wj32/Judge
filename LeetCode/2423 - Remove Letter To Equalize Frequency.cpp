class Solution {
public:
    bool equalFrequency(string word) {
        array<int, 26> f{};
        for (const auto c : word) {
            ++f[c - 'a'];
        }
        map<int, int> m;
        for (const auto n : f) {
            ++m[n];
        }
        m.erase(0);
        return (m.size() == 1 && (m.begin()->first == 1 ||
                                  m.begin()->second == 1)) ||
               (m.size() == 2 &&
                (m.begin()->first == 1 && m.begin()->second == 1 ||
                 (m.begin()->first + 1 == next(m.begin())->first &&
                  next(m.begin())->second == 1)));
    }
};