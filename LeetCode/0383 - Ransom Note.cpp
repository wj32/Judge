class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        array<int, 26> d = {};
        for (const char c : magazine) {
            d[c - 'a']++;
        }
        for (const char c : ransomNote) {
            d[c - 'a']--;
        }
        return all_of(d.begin(), d.end(), [&](int x) { return x >= 0; });
    }
};
