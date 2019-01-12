class Solution {
public:
    int numJewelsInStones(string J, string S) {
        const auto charToIndex = [&](char c) {
            if (c <= 'Z') {
                return c - 'A';
            }
            else {
                return 26 + c - 'a';
            }
        };
        array<bool, 52> jewels{};
        for (const char j : J) {
            jewels[charToIndex(j)] = true;
        }
        int count = 0;
        for (const char s : S) {
            count += jewels[charToIndex(s)];
        }
        return count;
    }
};
