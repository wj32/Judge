class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> r;
        for (int x = left; x <= right; x++) {
            const auto selfDividing = [&] {
                int remaining = x;
                while (remaining != 0) {
                    const int digit = remaining % 10;
                    if (digit == 0) {
                        return false;
                    }
                    if ((x % digit) != 0) {
                        return false;
                    }
                    remaining /= 10;
                }
                return true;
            }();
            if (selfDividing) {
                r.push_back(x);
            }
        }
        return r;
    }
};
