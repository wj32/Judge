class Solution {
public:
    int nextGreaterElement(int n) {
        auto s = to_string(n);
        if (s.size() == 1) {
            return -1;
        }

        int i;
        for (i = s.size() - 2; i >= 0; i--) {
            if (s[i] < s[i + 1]) {
                break;
            }
        }
        if (i < 0) {
            return -1;
        }

        int j;
        for (j = s.size() - 1; j > i; j--) {
            if (s[j] > s[i]) {
                break;
            }
        }

        swap(s[i], s[j]);
        sort(s.begin() + i + 1, s.end());

        const auto m = stoll(s);
        if (m > numeric_limits<int>::max()) {
            return -1;
        }
        return static_cast<int>(m);
    }
};
