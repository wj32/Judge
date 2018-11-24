class MedianFinder {
private:
    // Invariant: lower.size() == higher.size() or lower.size() == higher.size() + 1
    priority_queue<int, vector<int>, less<int>> lower;
    priority_queue<int, vector<int>, greater<int>> higher;

public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if (lower.empty() || (num <= lower.top())) {
            if (lower.size() != higher.size()) {
                higher.push(lower.top());
                lower.pop();
            }
            lower.push(num);
        }
        else {
            higher.push(num);
            if (lower.size() != higher.size()) {
                lower.push(higher.top());
                higher.pop();
            }
        }
    }

    double findMedian() {
        if (lower.size() == higher.size()) {
            return static_cast<double>(lower.top() + higher.top()) / 2;
        }
        else {
            return static_cast<double>(lower.top());
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
