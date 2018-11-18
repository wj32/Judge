class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while (n != 1) {
            if (s.find(n) != s.end()) {
                return false;
            }
            s.insert(n);

            int m = 0;
            while (n != 0) {
                const int d = n % 10;
                m += d * d;
                n /= 10;
            }

            n = m;
        }
        return true;
    }
};
