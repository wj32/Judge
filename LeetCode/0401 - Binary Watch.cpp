class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        const auto countBits = [&](int x) {
            int count = 0;
            while (x != 0) {
                count += x & 1;
                x >>= 1;
            }
            return count;
        };

        vector<string> r;
        for (int hours = 0; hours <= 11; hours++) {
            for (int minutes = 0; minutes <= 59; minutes++) {
                if (countBits(hours | (minutes << 4)) == num) {
                    r.push_back(to_string(hours) + ":" + ((minutes < 10) ? "0" : "") + to_string(minutes));
                }
            }
        }
        return r;
    }
};
