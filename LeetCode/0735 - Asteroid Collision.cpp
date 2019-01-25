class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;
        for (const int x : asteroids) {
            const int mx = abs(x);
            bool kx = true;
            while (!s.empty() && (s.back() > 0) && (x < 0)) {
                const int mb = abs(s.back());
                if (mb <= mx) {
                    s.pop_back();
                }
                if (mb >= mx) {
                    kx = false;
                    break;
                }
            }
            if (kx) {
                s.push_back(x);
            }
        }
        return s;
    }
};
