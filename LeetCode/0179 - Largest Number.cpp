class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for (const auto x : nums) {
            v.push_back(to_string(x));
        }
        sort(v.begin(), v.end(), [&](const auto& a, const auto& b) {
            return a + b > b + a;
        });

        string r;
        for (const auto s : v) {
            r += s;
        }

        int leadingZeros = 0;
        while ((leadingZeros < r.size() - 1) && (r[leadingZeros] == '0')) {
            leadingZeros++;
        }

        return r.substr(leadingZeros);
    }
};
