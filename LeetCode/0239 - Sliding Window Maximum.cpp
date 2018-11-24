class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 0) {
            return {};
        }
        vector<int> r(nums.size() - k + 1);
        deque<int> q;
        for (int i = 0; i < nums.size(); i++) {
            while (!q.empty() && (i - q.back() >= k)) {
                q.pop_back();
            }
            while (!q.empty() && (nums[q.front()] < nums[i])) {
                q.pop_front();
            }
            q.push_front(i);
            if (i >= k - 1) {
                r[i - k + 1] = nums[q.back()];
            }
        }
        return r;
    }
};
