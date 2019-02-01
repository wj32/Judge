class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        const int n = A.size();
        const int limit = min((n + 1) / 2, n - 1);
        const int totalSum = accumulate(A.begin(), A.end(), 0);

        sort(A.begin(), A.end(), [&](int a, int b) { return a > b; });

        vector<unordered_set<int>> sumsByCount(limit + 1);
        sumsByCount[0].insert(0);
        for (const int x : A) {
            for (int m = limit; m >= 1; m--) {
                for (const int sum : sumsByCount[m - 1]) {
                    if ((sum + x) * n >= totalSum * m) {
                        sumsByCount[m].insert(sum + x);
                    }
                }
            }
        }

        for (int m = 1; m <= limit; m++) {
            if ((((totalSum * m) % n) == 0) &&
                (sumsByCount[m].find(totalSum * m / n) != sumsByCount[m].end())) {
                return true;
            }
        }

        return false;
    }
};
