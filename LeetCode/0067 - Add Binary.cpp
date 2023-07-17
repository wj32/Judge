class Solution {
public:
    string addBinary(string a, string b) {
        string r;
        int c = 0;
        for (int i = 0; i < max(a.size(), b.size()); ++i) {
            const auto x = i < a.size() ? a[a.size() - i - 1] - '0' : 0;
            const auto y = i < b.size() ? b[b.size() - i - 1] - '0' : 0;
            r += '0' + (x ^ y ^ c);
            c = (x & y) | (c & (x ^ y));
        }
        if (c) {
            r += '1';
        }
        reverse(r.begin(), r.end());
        return r;
    }
};