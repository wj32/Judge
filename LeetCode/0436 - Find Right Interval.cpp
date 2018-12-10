/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<pair<int, int>> v(intervals.size());
        for (int i = 0; i < intervals.size(); i++) {
            v[i] = {intervals[i].start, i};
        }
        sort(v.begin(), v.end(), [&](const auto& a, const auto& b) {
            return a.first < b.first;
        });
        vector<int> r(v.size());
        for (int i = 0; i < intervals.size(); i++) {
            const auto it = lower_bound(v.begin(), v.end(), intervals[i].end, [&](const auto& a, int b) {
                return a.first < b;
            });
            r[i] = (it != v.end()) ? it->second : -1;
        }
        return r;
    }
};
