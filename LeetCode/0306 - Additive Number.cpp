class Solution {
public:
    bool recurse(const string& s, long long a, long long b, int count, size_t index) {
        if (index == s.size()) {
            return count >= 3;
        }

        if (s[index] == '0') {
            index++;
            if ((count < 2) || (a + b == 0)) {
                if (recurse(s, b, 0, count + 1, index)) {
                    return true;
                }
            }
        }
        else {
            long long number = 0;
            do {
                const int digit = s[index] - '0';
                index++;

                if (number * 10 < number) {
                    break;
                }
                number *= 10;
                if (number + digit < number) {
                    break;
                }
                number += digit;

                if ((count < 2) || (a + b == number)) {
                    if (recurse(s, b, number, count + 1, index)) {
                        return true;
                    }
                }
                else if (a + b < number) {
                    break;
                }
            } while (index < s.size());
        }

        return false;
    };

    bool isAdditiveNumber(string num) {
        return recurse(num, 0, 0, 0, 0);
    }
};
