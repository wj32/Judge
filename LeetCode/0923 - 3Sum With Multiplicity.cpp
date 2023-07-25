class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const int prime = 1000000007;
        array<long, 101> counts{};
        for (const auto x : arr) {
            ++counts[x];
        }
        long result = 0;
        for (int x = 0; x < counts.size(); ++x) {
            if (counts[x] == 0) {
                continue;
            }
            // 1, 1, 1
            for (int y = max(x, target - x - static_cast<int>(counts.size())) + 1; y < counts.size() && target - x - y > y; ++y) {
                result += counts[x] * counts[y] * counts[target - x - y];
            }
            // 1, 2
            if ((target - x) % 2 == 0 && (target - x) / 2 > x && (target - x) / 2 < counts.size()) {
                const auto n = counts[(target - x) / 2];
                result += counts[x] * (n * (n - 1) / 2);
            }
            // 2, 1
            if (target - x * 2 > x && target - x * 2 < counts.size()) {
                const auto n = counts[x];
                result += counts[target - x * 2] * (n * (n - 1) / 2);
            }
            // 3
            if (target == x * 3) {
                const auto n = counts[x];
                result += n * (n - 1) * (n - 2) / 6;
            }
            result %= prime;
        }
        return static_cast<int>(result);
    }
};