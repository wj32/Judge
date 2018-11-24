class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int a = 0;
        for (const int x : nums) {
            a ^= x;
        }

        const int b = a & -a;

        int c = 0;
        for (const int x : nums) {
            if ((x & b) != 0) {
                c ^= x;
            }
        }

        return {c, c ^ a};
    }
};
