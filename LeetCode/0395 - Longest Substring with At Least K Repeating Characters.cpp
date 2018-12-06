class Solution {
public:
    int recurse(const string& s, int k, int start, int end, const array<int, 26>& counts) {
        int maximum = 0;
        int subStart = start;
        array<int, 26> subCounts{};

        for (int i = start; i < end; i++) {
            if (counts[s[i] - 'a'] < k) {
                if (subStart < i) {
                    maximum = max(maximum, recurse(s, k, subStart, i, subCounts));
                    subCounts = {};
                }
                subStart = i + 1;
            }
            else {
                subCounts[s[i] - 'a']++;
            }
        }

        if (subStart == start) {
            maximum = end - start;
        }
        else if (subStart < end) {
            maximum = max(maximum, recurse(s, k, subStart, end, subCounts));
        }

        return maximum;
    }

    int longestSubstring(string s, int k) {
        array<int, 26> counts{};
        for (const char c : s) {
            counts[c - 'a']++;
        }
        return recurse(s, k, 0, s.size(), counts);
    }
};
