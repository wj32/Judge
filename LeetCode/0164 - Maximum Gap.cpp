class Solution {
public:
    struct Segment {
        bool valid;
        int low;
        int high;
    };

    int maximumGap(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        const auto minimum = *min_element(nums.begin(), nums.end());
        const auto maximum = *max_element(nums.begin(), nums.end());
        const auto range = maximum - minimum;
        if (range == 0) {
            return 0;
        }

        const auto minMaxGap = max(range / (static_cast<int>(nums.size()) - 1), 1);

        const auto initialSegment = Segment{false, numeric_limits<int>::max(), numeric_limits<int>::min()};
        vector<Segment> segments((range + minMaxGap) / minMaxGap, initialSegment);

        for (const int x : nums) {
            const auto segment = &segments[(x - minimum) / minMaxGap];
            segment->valid = true;
            segment->low = min(segment->low, x);
            segment->high = max(segment->high, x);
        }

        int maxGap = minMaxGap;
        bool previousHighValid = false;
        int previousHigh = 0;

        for (const auto& segment : segments) {
            if (segment.valid) {
                if (previousHighValid) {
                    maxGap = max(maxGap, segment.low - previousHigh);
                }
                previousHigh = segment.high;
                previousHighValid = true;
            }
        }

        return maxGap;
    }
};
