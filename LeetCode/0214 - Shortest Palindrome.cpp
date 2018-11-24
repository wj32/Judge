class Solution {
public:
    string shortestPalindrome(string s) {
        int k;
        vector<int> r(1 + s.size());
        r[0] = -1;

        k = -1;
        for (int i = 1; i <= s.size(); i++) {
            while ((k >= 0) && (s[k] != s[i - 1])) {
                k = r[k];
            }
            k++;
            r[i] = k;
        }

        k = 0;
        for (int i = 1; i <= s.size(); i++) {
            while ((k >= 0) && (s[k] != s[s.size() - i])) {
                k = r[k];
            }
            k++;
        }

        auto t = s.substr(k) + s;
        reverse(t.begin(), t.begin() + (s.size() - k));
        return t;
    }
};
