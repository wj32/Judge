class Solution {
public:
    void consumeWhitespace(const string& s, size_t* index) {
        while ((*index < s.size()) && (s[*index] == ' ')) {
            (*index)++;
        }
    }

    int evaluate(const string& s, size_t* index) {
        int result = 0;

        while (true) {
            consumeWhitespace(s, index);

            if (*index == s.size()) {
                break;
            }

            if (s[*index] == ')') {
                (*index)++;
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

            int number;

            if (s[*index] == '(') {
                (*index)++;
                number = evaluate(s, index);
            }
            else {
                assert((s[*index] >= '0') && (s[*index] <= '9'));
                number = 0;
                while ((*index < s.size()) && (s[*index] >= '0') && (s[*index] <= '9')) {
                    number *= 10;
                    number += s[*index] - '0';
                    (*index)++;
                }
            }

            result += sign * number;
        }

        return result;
    }

    int calculate(string s) {
        size_t index = 0;
        return evaluate(s, &index);
    }
};
