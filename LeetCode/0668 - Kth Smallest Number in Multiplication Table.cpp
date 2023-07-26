class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        if (m > n) {
            swap(m, n);
        }
        int low = 1;
        int high = m * n;
        while (low < high) {
            const auto mid = (low + high) / 2;
            const auto count = [&] {
                int count = 0;
                for (int i = 1; i <= m; ++i) {
                    count += min(mid / i, n);
                }
                return count;
            }();
            if (count < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};