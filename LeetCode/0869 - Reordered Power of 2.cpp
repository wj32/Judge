class Solution {
public:
    bool reorderedPowerOf2(int N) {
        const auto limit = 1000000000;
        auto s = to_string(N);
        sort(s.begin(), s.end());

        int k = 1;
        while (k <= limit) {
            auto t = to_string(k);
            if (t.size() == s.size()) {
                sort(t.begin(), t.end());
                if (t == s) {
                    return true;
                }
            }
            else if (t.size() > s.size()) {
                break;
            }
            k *= 2;
        }

        return false;
    }
};
