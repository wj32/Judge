class Solution {
private:
    vector<int> a;

    random_device rd;
    mt19937 gen;

public:
    Solution(vector<int> nums) : gen(rd()) {
        a = nums;
    }

    int pick(int target) {
        int index = -1;
        int count = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == target) {
                count++;
                std::uniform_int_distribution<> dist(1, count);
                if (dist(gen) == 1) {
                    index = i;
                }
            }
        }
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
