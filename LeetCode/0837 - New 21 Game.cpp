class Solution {
public:
    double new21Game(int N, int K, int W) {
        vector<double> r(N + 1);
        fill(r.begin() + K, r.end(), 1.0);
        double sum = min(N - K + 1, W);
        for (int i = K - 1; i >= 0; i--) {
            r[i] = sum / W;
            if (i + W < r.size()) {
                sum -= r[i + W];
            }
            sum += r[i];
        }
        return r[0];
    }
};
