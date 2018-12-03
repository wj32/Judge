class Solution {
private:
    vector<int> originalNums;
    vector<int> nums;

    random_device rd;
    mt19937 gen;

public:
    Solution(vector<int> v) : gen(rd()) {
        originalNums = v;
        nums = v;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return originalNums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (int i = 0; i + 1 < nums.size(); i++) {
            std::uniform_int_distribution<> dist(i, nums.size() - 1);
            swap(nums[i], nums[dist(gen)]);
        }
        return nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
