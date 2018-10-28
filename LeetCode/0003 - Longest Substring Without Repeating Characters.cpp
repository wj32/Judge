class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        array<int, 256> seen;
        fill(seen.begin(), seen.end(), -1);
        int longest = 0;
        int start = 0;

        for (int i = 0; i < s.size(); i++) {
            int before = seen[s[i]];
            if (before < start) {
                const int len = i - start + 1;
                if (longest < len) {
                    longest = len;
                }
            } else {
                start = before + 1;
            }
            seen[s[i]] = i;
        }

        return longest;
    }
};
