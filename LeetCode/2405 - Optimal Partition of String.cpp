class Solution {
public:
    int partitionString(string s) {
        array<bool, 26> used{};
        int result = 1;
        for (const auto c : s) {
            if (used[c - 'a']) {
                ++result;
                used.fill(false);
            }
            used[c - 'a'] = true;
        }
        return result;
    }
};