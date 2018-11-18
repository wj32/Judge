class Solution {
public:
    void reverse(vector<int>* a, int start, int count) {
        for (int i = 0; i < count / 2; i++) {
            swap((*a)[start + i], (*a)[start + count - 1 - i]);
        }
    }

    void rotate(vector<int>& nums, int k) {
        if (nums.size() == 0) {
            return;
        }

        k %= nums.size();

        reverse(&nums, 0, nums.size());
        reverse(&nums, 0, k);
        reverse(&nums, k, nums.size() - k);
    }
};
