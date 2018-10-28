class Solution {
public:
    string getPermutation(int n, int k) {
        vector<char> c(n);
        int m = 1;
        for (int i = 1; i <= n; i++) {
            c[i - 1] = '0' + i;
            m *= i;
        }

        k--;

        string s(n, '\0');
        for (int i = 0; i < n; i++) {
            m /= n - i;
            const int d = k / m;
            k %= m;
            s[i] = c[d];
            c.erase(c.begin() + d);
        }

        return s;
    }
};
