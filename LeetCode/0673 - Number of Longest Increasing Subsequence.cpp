class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<pair<int, int>> a(nums.size(), {0, 1});
        int maxLength = 0;
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (a[i].first <= a[j].first) {
                        a[i] = {a[j].first + 1, a[j].second};
                        maxLength = max(maxLength, a[i].first);
                    }
                    else if (a[i].first == a[j].first + 1) {
                        a[i].second += a[j].second;
                    }
                }
            }
        }

        int totalCount = 0;
        for (const auto& p : a) {
            if (p.first == maxLength) {
                totalCount += p.second;
            }
        }
        return totalCount;
    }
};
