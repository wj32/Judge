class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        map<int, int> m;
        for (const auto x : nums) {
            ++m[x];
        }
        const auto maxValue = m.rbegin()->first;
        int beauty = 0;
        int maxBeauty = 0;
        auto begin = m.begin();
        auto end = m.begin();
        for (int x = 0; x <= maxValue; ++x) {
            while (begin != m.end() && begin->first < x - k) {
                beauty -= begin->second;
                ++begin;
            }
            while (end != m.end() && end->first <= x + k) {
                beauty += end->second;
                ++end;
            }
            maxBeauty = max(maxBeauty, beauty);
        }
        return maxBeauty;
    }
};