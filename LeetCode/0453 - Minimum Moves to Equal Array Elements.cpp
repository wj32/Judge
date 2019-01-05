class Solution {
public:
    int minMoves(vector<int>& nums) {
        const int minimum = *min_element(nums.begin(), nums.end());
        return accumulate(nums.begin(), nums.end(), 0) - minimum * nums.size();
    }
};
