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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;

        int i;
        for (i = 0; i < intervals.size(); i++) {
            if (newInterval.start <= intervals[i].end) {
                break;
            }
            result.push_back(intervals[i]);
        }

        int x = newInterval.start;
        int y = newInterval.end;

        for (; i < intervals.size(); i++) {
            if (newInterval.end < intervals[i].start) {
                break;
            }
            x = min(x, intervals[i].start);
            y = max(y, intervals[i].end);
        }

        result.push_back({x, y});

        for (; i < intervals.size(); i++) {
            result.push_back(intervals[i]);
        }

        return result;
    }
};
