class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += k) {
            const int n = min(k, static_cast<int>(s.size()) - i);
            reverse(s.begin() + i, s.begin() + i + n);
            i += k;
        }
        return s;
    }
};
