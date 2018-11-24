class Solution {
public:
    int hIndex(vector<int>& citations) {
        int low = 0;
        int high = citations.size();

        while (low < high) {
            const int mid = low + (high - low + 1) / 2;
            if (citations[citations.size() - mid] >= mid) {
                low = mid;
            }
            else {
                high = mid - 1;
            }
        }

        return high;
    }
};
