class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int max2 = numeric_limits<int>::min();
        int max1 = numeric_limits<int>::min();
        for (const int x : A) {
            if (x < max2) {
                return false;
            }
            max2 = max1;
            max1 = max(max1, x);
        }
        return true;
    }
};
