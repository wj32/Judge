class Solution {
public:
    void recurse(vector<int>* r, int n, int k) {
        r->push_back(k);
        const int tenK = 10 * k;
        if (tenK <= n) {
            const int limit = min(n - tenK, 9);
            for (int j = 0; j <= limit; j++) {
                recurse(r, n, tenK + j);
            }
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> r;
        r.reserve(n);
        const int limit = min(n, 9);
        for (int k = 1; k <= limit; k++) {
            recurse(&r, n, k);
        }
        return r;
    }
};
