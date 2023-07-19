class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        const auto total = accumulate(arr.begin(), arr.end(), 0);
        if (total % 3 != 0) {
            return false;
        }
        const auto part = total / 3;
        int left = 0;
        for (size_t i = 0; i < arr.size() - 1; ++i) {
            left += arr[i];
            if (left == part) {
                int mid = 0;
                for (size_t j = i + 1; j < arr.size() - 1; ++j) {
                    mid += arr[j];
                    if (mid == part) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};