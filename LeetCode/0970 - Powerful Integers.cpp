class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        if (x > y) {
            swap(x, y);
        }
        if (y == 1) {
            return bound >= 2 ? vector{2} : vector<int>();
        }
        unordered_set<int> r;
        for (int b = 1; b < bound; b *= y) {
            if (x == 1) {
                r.insert(b + 1);
            } else {
                for (int a = 1; a + b <= bound; a *= x) {
                    r.insert(a + b);
                }
            }
        }
        return vector<int>(r.begin(), r.end());
    }
};