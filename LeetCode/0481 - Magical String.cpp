class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        int i = 2;
        while (s.size() < n) {
            s.append(s[i] - '0', s.back() == '1' ? '2' : '1');
            ++i;
        }
        return count(s.begin(), s.begin() + n, '1');
    }
};