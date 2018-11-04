class Solution {
public:
    void recurse(vector<string>* r, string* b, const string& s, int n, int k) {
        const auto p1 = (n == 4);
        const auto p2 = (k == s.size());
        if (p1 || p2) {
            if (p1 && p2) {
                r->push_back(*b);
            }
            return;
        }

        for (int j = 1; j <= 3; j++) {
            if (k + j > s.size()) {
                break;
            }

            const int x = [&] {
                int x = 0;
                for (int i = 0; i < j; i++) {
                    x *= 10;
                    x += s[k + i] - '0';
                }
                return x;
            }();

            if ((x <= 255) &&
                ((j == 1) ||
                    ((j == 2) && (x >= 10)) ||
                    ((j == 3) && (x >= 100)))) {
                const int old = b->size();
                if (n != 0) {
                    b->append(1, '.');
                }
                b->append(s, k, j);

                recurse(r, b, s, n + 1, k + j);

                b->erase(old, b->size() - old);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> r;
        string b;
        recurse(&r, &b, s, 0, 0);
        return r;
    }
};
