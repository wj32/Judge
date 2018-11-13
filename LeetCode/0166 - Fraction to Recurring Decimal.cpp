class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long n = numerator;
        long long d = denominator;

        assert(d != 0);

        if (n == 0) {
            return "0";
        }

        if (d < 0) {
            n = -n;
            d = -d;
        }

        string sign = "";

        if (n < 0) {
            sign = "-";
            n = -n;
        }

        const auto whole = to_string(n / d);
        n %= d;

        string s;
        map<long long, int> m;
        int repeatedFromIndex = -1;

        while (n != 0) {
            assert(n < d);

            do {
                const auto it = m.find(n);
                if (it != m.end()) {
                    repeatedFromIndex = it->second;
                    break;
                }
                m.insert({n, static_cast<int>(s.size())});

                n *= 10;
                s.append(1, '0');
            } while (n < d);

            if (repeatedFromIndex != -1) {
                break;
            }

            const auto quotient = to_string(n / d);
            n %= d;

            copy(quotient.begin(), quotient.end(), s.end() - quotient.size());
        }

        if (repeatedFromIndex != -1) {
            s.insert(repeatedFromIndex, 1, '(');
            s.append(1, ')');
        }

        return sign + whole + (s.empty() ? "" : ".") + s;
    }
};
