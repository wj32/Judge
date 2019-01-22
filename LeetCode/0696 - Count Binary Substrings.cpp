class Solution {
public:
    int countBinarySubstrings(string s) {
        if (s.empty()) {
            return 0;
        }
        int total = 0;
        int i = 1;
        while ((i < s.size()) && (s[i] == s[0])) {
            i++;
        }
        int oppositeRunLength = i;
        while (i < s.size()) {
            int j = i + 1;
            while ((j < s.size()) && (s[j] == s[i])) {
                j++;
            }
            const int runLength = j - i;
            total += min(runLength, oppositeRunLength);
            oppositeRunLength = runLength;
            i = j;
        }
        return total;
    }
};
