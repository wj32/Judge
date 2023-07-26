class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) {
            return "0";
        }
        string r;
        while (n != 0) {
            auto d = n % -2;
            n /= -2;
            if (d < 0) {
                d += 2;
                ++n;
            }
            r.push_back('0' + d);
        }
        reverse(r.begin(), r.end());
        return r;
    }
};