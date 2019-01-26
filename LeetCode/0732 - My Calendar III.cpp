class MyCalendarThree {
private:
    struct Entry {
        int end;
        int count;
    };

    map<int, Entry> intervals;
    int maxCount = 0;

public:
    MyCalendarThree() {

    }

    int book(int start, int end) {
        auto it = intervals.lower_bound(end);

        maxCount = max(maxCount, 1);

        auto itp = it;
        while (it != intervals.begin()) {
            itp = prev(it);
            assert(itp->first < end);
            if (itp->second.end <= start) {
                break;
            }

            if (itp->second.end < end) {
                if ((it != intervals.end()) && (it->first == end) && (it->second.count == 1)) {
                    end = it->second.end;
                    it = intervals.erase(it);
                }
                it = intervals.insert(it, {itp->second.end, {end, 1}});
                end = itp->second.end;
            }
            else if (itp->second.end > end) {
                it = intervals.insert(it, {end, {itp->second.end, itp->second.count}});
                itp->second.end = end;
            }

            if (itp->first >= start) {
                if ((it != intervals.end()) && (it->first == end) && (it->second.count == itp->second.count + 1)) {
                    end = it->second.end;
                    it = intervals.erase(it);
                }

                itp->second.end = end;
                itp->second.count++;
                maxCount = max(maxCount, itp->second.count);
            }
            else {
                const pair<int, Entry> element{start, {itp->second.end, itp->second.count + 1}};
                itp->second.end = start;
                it = intervals.insert(it, element);
                maxCount = max(maxCount, element.second.count);
                end = start;
                break;
            }

            end = itp->first;
            it = itp;
        }

        if (start < end) {
            if ((it != intervals.end()) && (it->first == end) && (it->second.count == 1)) {
                end = it->second.end;
                it = intervals.erase(it);
            }

            if ((it != intervals.begin()) && (itp->second.end == start) && (itp->second.count == 1)) {
                itp->second.end = end;
            }
            else {
                it = intervals.insert(it, {start, {end, 1}});
            }
        }

        return maxCount;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */
