class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<pair<int, int>> v(nums.size());
        for (int i = 0; i < v.size(); i++) {
            v[i] = {-nums[i], i};
        }
        sort(v.begin(), v.end());

        vector<string> r(v.size());
        if (v.size() >= 1) {
            r[v[0].second] = "Gold Medal";
            if (v.size() >= 2) {
                r[v[1].second] = "Silver Medal";
                if (r.size() >= 3) {
                    r[v[2].second] = "Bronze Medal";
                }
            }
        }
        for (int i = 3; i < v.size(); i++) {
            r[v[i].second] = to_string(i + 1);
        }
        return r;
    }
};
