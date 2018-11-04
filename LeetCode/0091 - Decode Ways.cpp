class Solution {
public:
    int numDecodings(string s) {
        const auto n = s.size();
        vector<int> r(n + 1, 0);

        r[n] = 1;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != '0') {
                r[i] += r[i + 1];
            }

            if ((i < n - 1) &&
                ((s[i] == '1') || ((s[i] == '2') && (s[i + 1] <= '6')))) {
                r[i] += r[i + 2];
            }
        }

        return r[0];
    }
};
