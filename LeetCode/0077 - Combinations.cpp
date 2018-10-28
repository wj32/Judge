class Solution {
public:
    void recurse(vector<vector<int>>* r, vector<int>* v, int n, int i, int j) {
        if (i == v->size()) {
            r->push_back(*v);
            return;
        }
        else if (j == n) {
            return;
        }

        (*v)[i] = j + 1;
        recurse(r, v, n, i + 1, j + 1);

        recurse(r, v, n, i, j + 1);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> r;
        vector<int> v(k);

        recurse(&r, &v, n, 0, 0);

        return r;
    }
};
