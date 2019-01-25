class MyCalendar {
private:
    map<int, int> intervals;

public:
    MyCalendar() {

    }

    bool book(int start, int end) {
        auto it = intervals.lower_bound(end);
        const auto itp = (it != intervals.begin()) ? prev(it) : intervals.end();

        if ((itp != intervals.end()) && (itp->second > start)) {
            return false;
        }

        if ((it != intervals.end()) && (it->first == end)) {
            end = it->second;
            it = intervals.erase(it);
        }

        if ((itp != intervals.end()) && (itp->second == start)) {
            itp->second = end;
        }
        else {
            intervals.insert(it, {start, end});
        }

        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
