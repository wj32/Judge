class Solution {
public:
    int recurse(const vector<int>& nums, vector<int>* r, int x, int k) {
        if ((*r)[x] == -1) {
            if (x == 0) {
                (*r)[x] = 1;
            }
            else {
                if (k != nums.size()) {
                    if ((x >= nums[k]) && (recurse(nums, r, x - nums[k], k + 1) != 0)) {
                        (*r)[x] = 1;
                    }
                    else {
                        (*r)[x] = recurse(nums, r, x, k + 1);
                    }
                }
                else {
                    (*r)[x] = 0;
                }
            }
        }
        return (*r)[x];
    }

    bool canPartition(vector<int>& nums) {
        const auto totalSum = accumulate(nums.begin(), nums.end(), 0);
        if ((totalSum % 2) != 0) {
            return false;
        }
        const auto target = totalSum / 2;

        vector<int> r(target + 1, -1);
        recurse(nums, &r, target, 0);
        return r[target];
    }
};
