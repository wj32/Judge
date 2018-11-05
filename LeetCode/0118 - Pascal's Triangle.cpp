class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r;
        for (int i = 1; i <= numRows; i++) {
            vector<int> v(i);
            v[0] = 1;
            for (int j = 1; j < i - 1; j++) {
                v[j] = r.back()[j - 1] + r.back()[j];
            }
            v[i - 1] = 1;
            r.push_back(move(v));
        }
        return r;
    }
};
