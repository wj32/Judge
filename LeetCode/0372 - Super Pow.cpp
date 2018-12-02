class Solution {
public:
    int pow10(int x) {
        const auto x2 = (x * x) % 1337;
        const auto x4 = (x2 * x2) % 1337;
        const auto x8 = (x4 * x4) % 1337;
        return (x2 * x8) % 1337;
    }

    int superPow(int a, vector<int>& b) {
        vector<int> p(10);
        p[0] = 1;
        for (int i = 1; i <= 9; i++) {
            p[i] = static_cast<int>((static_cast<long long>(p[i - 1]) * a) % 1337);
        }

        int r = 1;
        for (const int d : b) {
            r = (pow10(r) * p[d]) % 1337;
        }
        return r;
    }
};
