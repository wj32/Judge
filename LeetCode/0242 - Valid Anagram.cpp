class Solution {
public:
    bool isAnagram(string s, string t) {
        array<int, 26> d = {};
        for (const char c : s) {
            d[c - 'a']++;
        }
        for (const char c : t) {
            d[c - 'a']--;
        }
        return all_of(d.begin(), d.end(), [&](int x) { return x == 0; });
    }
};
