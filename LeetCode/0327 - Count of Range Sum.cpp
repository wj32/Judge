class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        map<long long, int> s;
        int count = 0;
        long long sum = 0;
        s.insert({sum, 1});
        for (const int x : nums) {
            sum += x;
            auto it = s.lower_bound(sum - upper);
            while ((it != s.end()) && (it->first <= sum - lower)) {
                count += it->second;
                it++;
            }
            const auto r = s.insert({sum, 1});
            if (!r.second) {
                r.first->second++;
            }
        }
        return count;
    }
};
