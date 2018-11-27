class NumArray {
private:
    int n;
    vector<int> v;

public:
    NumArray(vector<int> nums) {
        n = nums.size();
        v = vector<int>(n * 2);
        copy(nums.begin(), nums.end(), v.begin() + n);
        for (int i = n - 1; i >= 0; i--) {
            v[i] = v[i * 2] + v[i * 2 + 1];
        }
    }

    void update(int i, int val) {
        int k = n + i;
        v[k] = val;
        while (k != 0) {
            k /= 2;
            v[k] = v[k * 2] + v[k * 2 + 1];
        }
    }

    int sumRange(int i, int j) {
        i = n + i;
        j = n + j + 1;
        int sum = 0;
        while (i < j) {
            if ((i % 2) != 0) {
                sum += v[i];
                i++;
            }
            else if ((j % 2) != 0) {
                j--;
                sum += v[j];
            }
            else {
                i /= 2;
                j /= 2;
            }
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
