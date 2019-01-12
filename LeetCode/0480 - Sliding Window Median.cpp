class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        // Invariant: right.size() == left.size() or
        //            right.size() == left.size() + 1
        multiset<int> left;
        multiset<int> right;

        const auto rightToLeft = [&]() {
            if (right.size() == left.size() + 2) {
                left.insert(*right.begin());
                right.erase(right.begin());
            }
        };

        const auto leftToRight = [&]() {
            if (right.size() + 1 == left.size()) {
                const auto it = prev(left.end());
                right.insert(*it);
                left.erase(it);
            }
        };

        const auto add = [&](int x) {
            if (right.empty() || (x >= *right.begin())) {
                right.insert(x);
                rightToLeft();
            }
            else {
                left.insert(x);
                leftToRight();
            }
        };

        const auto remove = [&](int x) {
            if (right.empty() || (x < *right.begin())) {
                const auto it = left.find(x);
                assert(it != left.end());
                left.erase(it);
                rightToLeft();
            }
            else {
                const auto it = right.find(x);
                assert(it != right.end());
                right.erase(it);
                leftToRight();
            }
        };

        const auto getMedian = [&]() {
            if (right.size() == left.size()) {
                return (static_cast<double>(*prev(left.end())) + *right.begin()) / 2;
            }
            else {
                assert(right.size() == left.size() + 1);
                return static_cast<double>(*right.begin());
            }
        };

        vector<double> r;
        r.reserve(nums.size() - k + 1);
        for (int i = 0; i < k; i++) {
            add(nums[i]);
        }
        r.push_back(getMedian());
        for (int i = k; i < nums.size(); i++) {
            remove(nums[i - k]);
            add(nums[i]);
            r.push_back(getMedian());
        }
        return r;
    }
};
