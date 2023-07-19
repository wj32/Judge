class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, std::vector<pair<int, int>>, std::greater<>> q;
        for (int i = 0; i < nums.size(); ++i) {
            q.emplace(nums[i], i);
            if (q.size() > k) {
                q.pop();
            }
        }
        std::vector<int> v;
        v.reserve(k);
        while (!q.empty()) {
            v.push_back(q.top().second);
            q.pop();
        }
        sort(v.begin(), v.end());
        for (auto& i : v) {
            i = nums[i];
        }
        return v;
    }
};