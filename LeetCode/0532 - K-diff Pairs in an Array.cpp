class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (const int x : nums) {
            m[x]++;
        }
        int count = 0;
        if (k == 0) {
            for (const auto& p : m) {
                if (p.second > 1) {
                    count++;
                }
            }
        }
        else if (k > 0) {
            for (const auto& p : m) {
                if (m.find(p.first + k) != m.end()) {
                    count++;
                }
            }
        }
        return count;
    }
};
