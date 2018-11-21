class Solution {
public:
    void consumeWhitespace(const string& s, size_t* index) {
        while ((*index < s.size()) && (s[*index] == ' ')) {
            (*index)++;
        }
    }

    int evaluateMult(const string& s, size_t* index) {
        int result = 1;

        while (true) {
            consumeWhitespace(s, index);

            if (*index == s.size()) {
                break;
            }

            if ((s[*index] == '+') || (s[*index] == '-')) {
                break;
            }

            int power = 1;

            if (s[*index] == '*') {
                (*index)++;
            }
            else if (s[*index] == '/') {
                (*index)++;
                power = -1;
            }

            consumeWhitespace(s, index);
            assert(*index < s.size());

            int number;

            assert((s[*index] >= '0') && (s[*index] <= '9'));
            number = 0;
            while ((*index < s.size()) && (s[*index] >= '0') && (s[*index] <= '9')) {
                number *= 10;
                number += s[*index] - '0';
                (*index)++;
            }

            if (power == 1) {
                result *= number;
            }
            else {
                result /= number;
            }
        }

        return result;
    }

    int evaluateAdd(const string& s, size_t* index) {
        int result = 0;

        while (true) {
            consumeWhitespace(s, index);

            if (*index == s.size()) {
                break;
            }

            int sign = 1;

            if (s[*index] == '+') {
                (*index)++;
            }
            else if (s[*index] == '-') {
                (*index)++;
                sign = -1;
            }

            consumeWhitespace(s, index);
            assert(*index < s.size());

            const int number = evaluateMult(s, index);
            result += sign * number;
        }

        return result;
    }

    int calculate(string s) {
        size_t index = 0;
        return evaluateAdd(s, &index);
    }
};
