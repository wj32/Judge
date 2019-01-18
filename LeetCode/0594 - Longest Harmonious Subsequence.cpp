class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> m;
        for (const int x : nums) {
            m[x]++;
        }

        int maxCount = 0;
        for (const auto& p : m) {
            const auto it = m.find(p.first + 1);
            if (it != m.end()) {
                maxCount = max(maxCount, p.second + it->second);
            }
        }
        return maxCount;
    }
};
