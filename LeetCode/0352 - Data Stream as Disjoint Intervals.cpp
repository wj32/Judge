/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
private:
    vector<Interval> intervals;

public:
    /** Initialize your data structure here. */
    SummaryRanges() {

    }

    void addNum(int val) {
        int start = val;
        int end = val;
        const auto cmp = [&](const Interval& a, const Interval& b) {
            return a.start < b.start;
        };
        auto it = upper_bound(intervals.begin(), intervals.end(), Interval{val, numeric_limits<int>::max()}, cmp);
        if (it != intervals.begin()) {
            auto itp = prev(it);
            assert(val >= itp->start);
            if (val <= itp->end) {
                return;
            }
            if (itp->end + 1 == val) {
                start = itp->start;
                it = intervals.erase(itp);
            }
        }
        if (it != intervals.end()) {
            if (val + 1 == it->start) {
                end = it->end;
                it = intervals.erase(it);
            }
        }
        intervals.insert(it, {start, end});
    }

    vector<Interval> getIntervals() {
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
