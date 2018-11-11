class Solution {
public:
    void recurse(vector<vector<string>>* r, vector<string>* v, const string& s, int k) {
        const auto n = s.size();

        if (k == n) {
            r->push_back(*v);
            return;
        }

        for (int j = 1; j <= n - k; j++) {
            const bool p = [&] {
                for (int i = 0; i < j / 2; i++) {
                    if (s[k + i] != s[k + j - 1 - i]) {
                        return false;
                    }
                }
                return true;
            }();

            if (p) {
                v->push_back(s.substr(k, j));
                recurse(r, v, s, k + j);
                v->pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        if (s.size() == 0) {
            return {};
        }
        vector<vector<string>> r;
        vector<string> v;
        recurse(&r, &v, s, 0);
        return r;
    }
};
