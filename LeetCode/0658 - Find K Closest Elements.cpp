class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int left = right;
        while (k != 0) {
            const int adjustment = [&] {
                if (left == 0) {
                    return k;
                }
                else if (right == arr.size()) {
                    return -k;
                }
                else {
                    if (arr[right] - x < x - arr[left - 1]) {
                        return 1;
                    }
                    else {
                        return -1;
                    }
                }
            }();
            if (adjustment < 0) {
                left += adjustment;
                k += adjustment;
            }
            else {
                right += adjustment;
                k -= adjustment;
            }
        }
        return vector<int>(arr.begin() + left, arr.begin() + right);
    }
};
