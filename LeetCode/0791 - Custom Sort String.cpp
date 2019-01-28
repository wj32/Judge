class Solution {
public:
    string customSortString(string S, string T) {
        array<int, 26> a{};
        for (const char c : T) {
            a[c - 'a']++;
        }

        string r;

        for (const char c : S) {
            r.append(a[c - 'a'], c);
            a[c - 'a'] = 0;
        }

        for (int i = 0; i < 26; i++) {
            r.append(a[i], 'a' + i);
        }

        return r;
    }
};
