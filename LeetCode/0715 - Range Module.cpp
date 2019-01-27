class RangeModule {
    struct Entry {
        int right;
        bool value;
    };

    map<int, Entry> intervals;

    void setRange(int left, int right, bool value) {
        // cout << "setting [" << left << ", " << right << ") to " << value << endl;

        auto it = intervals.lower_bound(right);

        while (it != intervals.begin()) {
            auto itp = prev(it);
            assert(itp->first < right);
            if (itp->second.right <= left) {
                break;
            }

            if (itp->second.right > right) {
                if (itp->second.value != value) {
                    it = intervals.insert(it, {right, {itp->second.right, itp->second.value}});
                    itp->second.right = right;
                }
                else {
                    right = itp->first;
                    it = itp;
                    continue;
                }
            }

            if (itp->first > left) {
                itp = intervals.erase(itp);
            }
            else {
                if ((itp->first == left) || (itp->second.value == value)) {
                    if ((it != intervals.end()) && (it->first == right) && (it->second.value == value)) {
                        right = it->second.right;
                        it = intervals.erase(it);
                    }
                    itp->second.right = right;
                    itp->second.value = value;
                    right = left;
                }
                else {
                    itp->second.right = left;
                }

                break;
            }

            right = itp->first;
            it = itp;
        }

        if (left < right) {
            if ((it != intervals.end()) && (it->first == right) && (it->second.value == value)) {
                right = it->second.right;
                it = intervals.erase(it);
            }
            intervals.insert(it, {left, {right, value}});
        }

        // for (const auto& p : intervals) {
        //     cout << "[" << p.first << ", " << p.second.right << "): " << p.second.value << "   ";
        // }
        // cout << endl;
    }

public:
    RangeModule() {
        intervals.insert({0, {numeric_limits<int>::max(), false}});
    }

    void addRange(int left, int right) {
        setRange(left, right, true);
    }

    bool queryRange(int left, int right) {
        auto it = intervals.lower_bound(right);

        while (it != intervals.begin()) {
            it = prev(it);
            assert(it->first < right);
            if (it->second.right <= left) {
                break;
            }

            if (!it->second.value) {
                return false;
            }
        }

        return true;
    }

    void removeRange(int left, int right) {
        setRange(left, right, false);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */
