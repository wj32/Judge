class Solution {
public:
    string addStrings(string num1, string num2) {
        const int n1 = num1.size();
        const int n2 = num2.size();
        const int n = max(n1, n2);

        string r;
        r.reserve(n + 1);

        int carry = 0;
        for (int i = 0; i < n; i++) {
            const int d1 = (i < n1) ? (num1[n1 - i - 1] - '0') : 0;
            const int d2 = (i < n2) ? (num2[n2 - i - 1] - '0') : 0;
            const int sum = d1 + d2 + carry;
            carry = (sum >= 10) ? 1 : 0;
            const int d = (carry == 0) ? sum : (sum - 10);
            r.append(1, '0' + d);
        }

        if (carry != 0) {
            r.append(1, '1');
        }

        reverse(r.begin(), r.end());

        return r;
    }
};
