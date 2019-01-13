class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if (nums.size() == 0) {
            return {};
        }

        vector<int> r(nums.size());
        stack<int> s;
        int index = max_element(nums.begin(), nums.end()) - nums.begin();

        s.push(nums[index]);
        r[index] = -1;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (index != 0) {
                index--;
            }
            else {
                index = nums.size() - 1;
            }
            const int x = nums[index];
            while (!s.empty() && (s.top() <= x)) {
                s.pop();
            }
            r[index] = !s.empty() ? s.top() : -1;
            s.push(x);
        }

        return r;
    }
};
