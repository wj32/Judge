class Solution {
public:
    string recurse(const string& s, size_t* index) {
        string result;

        while (*index < s.size()) {
            if (s[*index] == ']') {
                (*index)++;
                break;
            }
            else if ((s[*index] >= '0') && (s[*index] <= '9')) {
                int number = 0;
                while ((*index < s.size()) && (s[*index] >= '0') && (s[*index] <= '9')) {
                    number *= 10;
                    number += s[*index] - '0';
                    (*index)++;
                }

                assert((*index < s.size()) && (s[*index] == '['));
                (*index)++;

                const auto innerResult = recurse(s, index);
                result.reserve(result.size() + (innerResult.size() * number));
                for (int i = 0; i < number; i++) {
                    result.append(innerResult);
                }
            }
            else {
                result.append(1, s[*index]);
                (*index)++;
            }
        }

        return result;
    };

    string decodeString(string s) {
        size_t index = 0;
        return recurse(s, &index);
    }
};
