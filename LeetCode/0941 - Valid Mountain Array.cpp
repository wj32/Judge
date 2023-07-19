class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3 || arr[0] >= arr[1]) {
            return false;
        }
        bool down = false;
        auto prev = -1;
        for (const auto x : arr) {
            if (x > prev) {
                if (down) {
                    return false;
                }
            } else if (x < prev) {
                down = true;
            } else {
                return false;
            }
            prev = x;
        }
        return down;
    }
};