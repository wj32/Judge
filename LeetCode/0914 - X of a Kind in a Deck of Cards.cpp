class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> m;
        for (const auto x : deck) {
            ++m[x];
        }
        int r = m.begin()->second;
        for (const auto& [x, n] : m) {
            r = gcd(r, n);
        }
        return r > 1;
    }
};