class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int, int> m;
        for (int i = 0; i < findNums.size(); i++) {
            m.insert({findNums[i], i});
        }

        vector<int> r(findNums.size());
        stack<int> s;
        for (int i = nums.size() - 1; i >= 0; i--) {
            const int x = nums[i];
            while (!s.empty() && (s.top() <= x)) {
                s.pop();
            }

            const auto it = m.find(x);
            if (it != m.end()) {
                r[it->second] = !s.empty() ? s.top() : -1;
            }

            s.push(x);
        }
        return r;
    }
};
