class Solution {
public:
    int factorial(int n) {
        int r = 1;

        for (int k = 2; k <= n; k++) {
            r *= k;
        }

        return r;
    }

    void fill(const vector<int>& nums, vector<vector<int>>* result, int base, int range, set<int>* indices, int position) {
        range /= indices->size();

        auto it = indices->cbegin();

        while (it != indices->cend()) {
            const auto x = *it;
            it++;

            indices->erase(x);

            for (int i = 0; i < range; i++) {
                (*result)[base + i][position] = nums[x];
            }

            if (!indices->empty()) {
                fill(nums, result, base, range, indices, position + 1);
            }

            indices->insert(x);

            base += range;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        const auto n = nums.size();
        const auto fn = factorial(static_cast<int>(n));
        set<int> indices;
        vector<vector<int>> result(fn);

        for (int k = 0; k < n; k++) {
            indices.insert(k);
        }

        for (int i = 0; i < fn; i++) {
            result[i].resize(n);
        }

        fill(nums, &result, 0, fn, &indices, 0);

        return result;
    }
};
