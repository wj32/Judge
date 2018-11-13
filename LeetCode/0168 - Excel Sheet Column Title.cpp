class Solution {
public:
    string convertToTitle(int n) {
        string s;

        do {
            n--;
            s.append(1, 'A' + (n % 26));
            n /= 26;
        } while (n != 0);

        reverse(s.begin(), s.end());

        return s;
    }
};
