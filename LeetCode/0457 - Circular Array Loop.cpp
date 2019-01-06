class Solution {
public:
    int mod(int k, int n) {
        return ((k % n) + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {
        const int n = nums.size();

        for (int i = 0; i < n; i++) {
            nums[i] = (nums[i] > 0) ? (nums[i] % n) : ((nums[i] % n) - n);
        }

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            const int id = n + i;
            if (x < n) {
                nums[i] = id;
                const bool forward = x >= 0;
                int j = i;
                while (true) {
                    const int k = mod(j + x, n);
                    if (k == j) {
                        break;
                    }
                    j = k;
                    x = nums[j];
                    if (x == id) {
                        return true;
                    }
                    if ((x >= n) || ((x >= 0) != forward)) {
                        break;
                    }
                    nums[j] = id;
                }
            }
        }

        return false;
    }
};
