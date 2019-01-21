class Solution {
public:
    int countSubstrings(string s) {
        string t((s.size() * 2) + 1, '\0');
        t[0] = ' ';
        for (int i = 0; i < s.size(); i++) {
            t[(i * 2) + 1] = s[i];
            t[(i * 2) + 2] = ' ';
        }

        vector<int> r(t.size(), 0);
        int center = 0;
        int span = 0;
        int i = 1;
        while (i < t.size()) {
            const int right = center + span + 1;
            if (i < right) {
                const int j = center - (i - center);
                r[i] = j - max(j - r[j], center - span);
            }
            if (i + r[i] + 1 >= right) {
                center = i;
                span = r[i];
                const int spanLimit = min(static_cast<int>(t.size()) - center - 1, center);
                while ((span < spanLimit) && (t[center + span + 1] == t[center - span - 1])) {
                    span++;
                }
                r[i] = span;
            }
            i++;
        }

        int total = 0;
        for (const int x : r) {
            total += (x + 1) / 2;
        }
        return total;
    }
};
