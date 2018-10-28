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
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() == 0) {
            return {};
        }

        sort(intervals.begin(), intervals.end(), [&](const auto& x, const auto& y) { return x.start < y.start; });

        vector<Interval> result = {intervals[0]};

        for (int i = 1; i < intervals.size(); i++) {
            const auto& x = intervals[i];

            if (result.back().end < x.start) {
                result.push_back(x);
            }
            else {
                result.back().end = max(result.back().end, x.end);
            }
        }

        return result;
    }
};
