class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        struct Entry {
            int count;
            int first;
            int last;
        };
        unordered_map<int, Entry> m;
        for (int i = 0; i < nums.size(); i++) {
            const auto result = m.insert({nums[i], {1, i, i}});
            if (!result.second) {
                result.first->second.count++;
                result.first->second.last = i;
            }
        }

        int maxCount = numeric_limits<int>::min();
        for (const auto& p : m) {
            maxCount = max(maxCount, p.second.count);
        }

        int minLength = numeric_limits<int>::max();
        for (const auto& p : m) {
            if (p.second.count == maxCount) {
                minLength = min(minLength, p.second.last - p.second.first);
            }
        }
        return minLength + 1;
    }
};
