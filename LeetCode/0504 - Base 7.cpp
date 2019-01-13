class Solution {
public:
    string convertToBase7(int num) {
        if (num < 0) {
            return "-" + convertToBase7(-num);
        }
        string s;
        do {
            s.append(1, '0' + (num % 7));
            num /= 7;
        } while (num != 0);
        reverse(s.begin(), s.end());
        return s;
    }
};
