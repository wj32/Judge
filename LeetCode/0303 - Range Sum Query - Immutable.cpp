class NumArray {
private:
    vector<int> acc;

public:
    NumArray(vector<int> nums) {
        acc = vector<int>(nums.size() + 1);
        acc[0] = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            acc[i + 1] = acc[i] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        return acc[j + 1] - acc[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
