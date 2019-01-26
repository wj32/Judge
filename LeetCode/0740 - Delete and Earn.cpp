class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        sort(nums.begin(), nums.end());

        vector<pair<int, int>> v{{nums[0], 1}};
        for (int i = 1; i < nums.size(); i++) {
            if (v.back().first == nums[i]) {
                v.back().second++;
            }
            else {
                v.push_back({nums[i], 1});
            }
        }

        if (v.size() == 1) {
            return v[0].first * v[0].second;
        }

        vector<int> r(v.size());

        for (int i = 0; i < r.size(); i++) {
            int prev = 0;

            int j = i - 1;
            if (j >= 0) {
                if (v[j].first + 1 == v[i].first) {
                    j--;
                }
                if (j >= 0) {
                    prev = r[j];
                }
                if (j >= 1) {
                    prev = max(prev, r[j - 1]);
                }
            }

            r[i] = prev + (v[i].first * v[i].second);
        }

        return max(r[r.size() - 1], r[r.size() - 2]);
    }
};
