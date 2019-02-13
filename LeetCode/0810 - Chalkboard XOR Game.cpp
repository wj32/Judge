class Solution {
public:
    bool xorGame(vector<int>& nums) {
        return ((nums.size() % 2 ) == 0) || (accumulate(nums.begin(), nums.end(), 0, bit_xor<>()) == 0);
    }
};
