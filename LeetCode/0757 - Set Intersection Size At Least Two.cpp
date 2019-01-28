class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](const auto& a, const auto& b) {
            if (a[1] != b[1]) {
                return a[1] < b[1];
            }
            else {
                return a[0] > b[0]; // (*)
            }
        });

        int count = 2;
        int x = intervals[0][1] - 1;
        int y = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            const auto start = intervals[i][0];
            const auto end = intervals[i][1];
            if (y < start) {
                count += 2;
                x = end - 1;
                y = end;
            }
            else if (x < start) {
                assert(y != end); // Guaranteed by sorting left endpoints in reverse (*)
                count++;
                x = y;
                y = end;
            }
        }
        return count;
    }
};
