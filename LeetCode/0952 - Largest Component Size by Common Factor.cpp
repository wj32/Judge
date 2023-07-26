class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        vector<int> parents(100001);
        for (int i = 0; i < parents.size(); ++i) {
            parents[i] = i;
        }
        const auto findRoot = [&](int i) {
            while (parents[i] != i) {
                auto& j = parents[i];
                j = parents[j];
                i = j;
            }
            return i;
        };
        const auto merge = [&](int i, int j) {
            parents[findRoot(i)] = findRoot(j);
        };
        for (const auto x : nums) {
            for (int y = 2; y <= static_cast<int>(sqrt(x)); ++y) {
                if (x % y == 0) {
                    merge(x, y);
                    merge(x, x / y);
                }
            }
        }
        vector<int> sizes(parents.size(), 0);
        int maxSize = 1;
        for (const auto x : nums) {
            auto& size = sizes[findRoot(x)];
            ++size;
            maxSize = max(maxSize, size);
        }
        return maxSize;
    }
};