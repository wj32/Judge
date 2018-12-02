class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }
        sort(nums.begin(), nums.end());
        vector<int> temp(nums.size());
        const int secondHalf = (nums.size() + 1) / 2;
        int src = (nums.size() - 1) / 2;
        int dst = 0;
        while (true) {
            temp[dst] = nums[src];
            dst++;
            if (src < secondHalf) {
                src += nums.size() / 2;
                if (src < secondHalf) {
                    break;
                }
            }
            else {
                src -= nums.size() / 2;
                src--;
                if (src < 0) {
                    break;
                }
            }
        }
        copy(temp.begin(), temp.end(), nums.begin());
    }
};
