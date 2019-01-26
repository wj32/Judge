class MyCalendarTwo {
private:
    struct Entry {
        int end;
        int count;
    };

    map<int, Entry> intervals;

public:
    MyCalendarTwo() {

    }

    bool book(int start, int end) {
        // cout << "booking [" << start << ", " << end << ")" << endl;

        auto it = intervals.lower_bound(end);

        auto itp = it;
        while (itp != intervals.begin()) {
            itp = prev(itp);
            assert(itp->first < end);
            if (itp->second.end <= start) {
                break;
            }

            if (itp->second.count == 2) {
                return false;
            }
        }

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
            }
            else {
                const pair<int, Entry> element{start, {itp->second.end, itp->second.count + 1}};
                itp->second.end = start;
                it = intervals.insert(it, element);
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

        // for (const auto& p : intervals) {
        //     cout << "[" << p.first << ", " << p.second.end << "): " << p.second.count << "   ";
        // }
        // cout << endl;

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */
