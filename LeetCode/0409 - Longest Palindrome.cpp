class Solution {
public:
    int longestPalindrome(string s) {
        array<int, 'z' - 'A' + 1> counts{};
        for (const char c : s) {
            counts[c - 'A']++;
        }
        int sum = 0;
        int oddCount = 0;
        for (const int count : counts) {
            sum += count;
            oddCount += count % 2;
        }
        return sum - max(0, oddCount - 1);
    }
};
