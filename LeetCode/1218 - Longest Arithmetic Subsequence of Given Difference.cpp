class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> m;
        int maxCount = 0;
        for (const auto x : arr) {
            const auto it = m.find(x - difference);
            const auto count = it != m.end() ? it->second : 0;
            auto& newCount = m[x];
            newCount = max(newCount, count + 1);
            maxCount = max(maxCount, newCount);
        }
        return maxCount;
    }
};