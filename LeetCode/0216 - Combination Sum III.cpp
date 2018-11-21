class Solution {
public:
    void recurse(vector<vector<int>>* r, vector<int>* v, int k, int n, int minimum) {
        if ((k == 0) && (n == 0)) {
            r->push_back(*v);
            return;
        }

        const int maximum = min(n, 9);

        for (int x = minimum; x <= maximum; x++) {
            v->push_back(x);
            recurse(r, v, k - 1, n - x, x + 1);
            v->pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> r;
        vector<int> v;
        v.reserve(n);
        recurse(&r, &v, k, n, 1);
        return r;
    }
};
