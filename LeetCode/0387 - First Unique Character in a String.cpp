class Solution {
public:
    int firstUniqChar(string s) {
        const int unseen = -1;
        const int repeated = -2;

        array<int, 26> a;
        a.fill(unseen);

        for (int i = 0; i < s.size(); i++) {
            const auto e = &a[s[i] - 'a'];
            if (*e == unseen) {
                *e = i;
            }
            else if (*e >= 0) {
                *e = repeated;
            }
        }

        int first = s.size();
        for (const auto x : a) {
            if (x >= 0) {
                first = min(first, x);
            }
        }
        return (first < s.size()) ? first : -1;
    }
};
