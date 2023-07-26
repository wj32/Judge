class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        for (size_t i = arr.size() - 1; i > 0; --i) {
            if (arr[i - 1] > arr[i]) {
                auto it = lower_bound(arr.begin() + i, arr.end(), arr[i - 1]);
                it = lower_bound(arr.begin() + i, it, *prev(it));
                swap(arr[i - 1], *it);
                break;
            }
        }
        return move(arr);
    }
};