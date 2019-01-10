class Solution {
public:
    void recurse(vector<int>& nums, int index, vector<char>& v, set<vector<char>>& s) {
        if (index == nums.size()) {
            return;
        }

        if (v.empty() || (v.back() <= nums[index])) {
            v.push_back(static_cast<char>(nums[index]));
            if (v.size() >= 2) {
                s.insert(v);
            }
            recurse(nums, index + 1, v, s);
            v.pop_back();
        }

        recurse(nums, index + 1, v, s);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<char> v;
        set<vector<char>> s;
        recurse(nums, 0, v, s);

        vector<vector<int>> r;
        r.reserve(s.size());
        for (const auto t : s) {
            r.push_back(vector<int>(t.begin(), t.end()));
        }
        return r;
    }
};
