class Solution {
public:
    int kInversePairs(int n, int k) {
        const int prime = 1000000007;
        const int nc2 = n * (n - 1) / 2;
        if ((k < 0) || (k > nc2)) {
            return 0;
        }
        if (k > nc2 / 2) {
            k = nc2 - k;
        }

        vector<long long> r(k + 1, 0);
        vector<long long> s(k + 1, 0);
        r[0] = 1;
        s[0] = 1;

        int mc2 = 1;
        for (int m = 2; m <= n; m++) {
            const int mid = mc2 / 2;
            const int limit2 = min(mid, k);
            const int limit1 = min(limit2, m - 1);
            for (int j = 1; j <= limit1; j++) {
                s[j] = (s[j - 1] + r[j]) % prime;
            }
            for (int j = limit1 + 1; j <= limit2; j++) {
                s[j] = (s[j - 1] + r[j] - r[j - m] + prime) % prime;
            }
            const int limit3 = min(mc2, k);
            for (int j = mid + 1; j <= limit3; j++) {
                s[j] = s[mc2 - j];
            }
            mc2 += m;
            // cout << m << ": ";
            // for (const int x : r) {
            //     cout << x << " ";
            // }
            // cout << endl;
            swap(r, s);
        }

        return static_cast<int>(r[k]);
    }
};
