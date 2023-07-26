class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        auto h = destination[1];
        auto v = destination[0];
        if (h == 0) {
            return string(v, 'V');
        }
        // ncr(h + v - 1, h - 1) to avoid overflow
        auto t = [&] {
            const auto n = h + v - 1;
            const auto r = min(h - 1, v);
            long a = n - r + 1;
            long t = 1;
            for (int b = 1; b <= r; ++a, ++b) {
                t *= a;
                t /= b;
            }
            return t;
        }();
        string path;
        while (h != 0 && v != 0) {
            if (k <= t) {
                path += 'H';
                t *= h - 1;
                t /= h + v - 1;
                --h;
            } else {
                path += 'V';
                k -= t;
                t *= v;
                t /= h + v - 1;
                --v;
            }
        }
        if (h != 0) {
            path.append(h, 'H');
        }
        if (v != 0) {
            path.append(v, 'V');
        }
        return path;
    }
};