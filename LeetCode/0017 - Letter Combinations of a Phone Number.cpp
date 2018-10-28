class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }

        map<int, pair<char, int>> m = {
            {2, {'a', 3}},
            {3, {'d', 3}},
            {4, {'g', 3}},
            {5, {'j', 3}},
            {6, {'m', 3}},
            {7, {'p', 4}},
            {8, {'t', 3}},
            {9, {'w', 4}}
        };

        vector<string> r;
        string s(digits.size(), '\0');

        for (int i = 0; i < digits.size(); i++) {
            s[i] = m[digits[i] - '0'].first;
        }

        while (true) {
            r.push_back(s);

            int i;
            for (i = 0; i < digits.size(); i++) {
                const int digit = digits[i] - '0';
                const int j = s[i] - m[digit].first;
                const int k = (j + 1) % m[digit].second;
                const bool carry = (j + 1) >= m[digit].second;
                s[i] = m[digit].first + k;
                if (!carry) {
                    break;
                }
            }

            if (i == digits.size()) {
                break;
            }
        }

        return r;
    }
};
