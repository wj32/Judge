class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        pair<int, int> a = {};
        pair<int, int> b = {};
        pair<int, int> c = {};

        for (const int x : nums) {
            if ((a.second != 0) && (a.first == x)) {
                a.second++;
            }
            else if ((b.second != 0) && (b.first == x)) {
                b.second++;
            }
            else if ((c.second != 0) && (c.first == x)) {
                c.second++;
            }
            else {
                c.first = x;
                c.second = 1;
            }

            if (c.second > b.second) {
                swap(b, c);
            }
            if (b.second > a.second) {
                swap(a, b);
            }
        }

        vector<int> r;
        const size_t goal = nums.size() / 3;
        const auto check = [&](pair<int, int> x) {
            if ((x.second != 0) &&
                (count(nums.begin(), nums.end(), x.first) > goal)) {
                r.push_back(x.first);
            }
        };

        check(a);
        check(b);
        check(c);

        return r;
    }
};
