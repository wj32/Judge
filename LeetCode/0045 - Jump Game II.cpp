class Solution {
public:
    int jump(vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        stack<tuple<int, int, int>> s;

        s.push({n - 1, 1, 0});

        for (int i = n - 2; i >= 0; i--) {
            const auto r = min(i + 1 + nums[i], n);

            while (get<0>(s.top()) + get<1>(s.top()) < r) {
                s.pop();
            }

            s.push({i, get<0>(s.top()) - i, get<2>(s.top()) + 1});
        }

        return get<2>(s.top());
    }
};
