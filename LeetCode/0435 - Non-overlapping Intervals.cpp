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
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](const auto& a, const auto& b) {
            return a.start < b.start;
        });
        int count = 0;
        int end = numeric_limits<int>::min();
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i].start >= end) {
                count++;
                end = intervals[i].end;
            }
            else {
                end = min(end, intervals[i].end);
            }
        }
        return intervals.size() - count;
    }
};
