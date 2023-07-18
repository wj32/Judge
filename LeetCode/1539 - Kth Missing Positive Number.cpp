class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int begin = 0;
        int end = arr.size();
        while (begin < end) {
            const auto mid = begin + (end - begin + 1) / 2;
            if (k > arr[mid - 1] - mid) {
                begin = mid;
            } else {
                end = mid - 1;
            }
        }
        return k + begin;
    }
};