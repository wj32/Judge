class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if (query_glass > query_row / 2) {
            query_glass = query_row - query_glass;
        }
        vector<double> u(query_glass + 2);
        vector<double> v(query_glass + 2);
        u[0] = poured;
        for (int row = 1; row <= query_row; row++) {
            const int limit = min(row, query_glass + 1);
            fill(v.begin(), v.begin() + limit + 1, 0.0);
            for (int i = 0; i < limit; i++) {
                if (u[i] > 1.0) {
                    const auto overflow = (u[i] - 1.0) / 2;
                    v[i] += overflow;
                    v[i + 1] += overflow;
                }
            }
            swap(u, v);
        }
        return min(u[query_glass], 1.0);
    }
};
