class Solution {
public:
    char findTheDifference(string s, string t) {
        array<int, 26> d = {};
        for (const char c : t) {
            d[c - 'a']++;
        }
        for (const char c : s) {
            d[c - 'a']--;
        }
        return 'a' + (find_if(d.begin(), d.end(), [&](int x) { return x != 0; }) - d.begin());
    }
};
