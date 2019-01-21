class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        const auto cmp = [&](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        };
        int maximum = numeric_limits<int>::min();
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        for (int i = 0; i < nums.size(); i++) {
            q.push({nums[i][0], i});
            maximum = max(maximum, nums[i][0]);
        }
        vector<int> indices(nums.size(), 1);
        pair<int, int> smallestRange = {0, numeric_limits<int>::max()};
        while (true) {
            const auto [minimum, listIndex] = q.top();
            if (smallestRange.second - smallestRange.first > maximum - minimum) {
                smallestRange = {minimum, maximum};
            }
            if (indices[listIndex] == nums[listIndex].size()) {
                break;
            }
            const auto value = nums[listIndex][indices[listIndex]];
            indices[listIndex]++;
            if (value != minimum) {
                q.pop();
                q.push({value, listIndex});
                maximum = max(maximum, value);
            }
        }
        return {smallestRange.first, smallestRange.second};
    }
};
