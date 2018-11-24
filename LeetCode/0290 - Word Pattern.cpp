class Solution {
public:
    bool wordPattern(string pattern, string str) {
        array<string, 26> r;
        map<string, char> s;
        size_t i = 0;

        for (const char c : pattern) {
            if (i == str.size()) {
                return false;
            }
            size_t j = i;
            while ((j < str.size()) && (str[j] != ' ')) {
                j++;
            }

            const auto word = str.substr(i, j - i);
            const auto it = s.find(word);
            if (r[c - 'a'].empty() && (it == s.end())) {
                r[c - 'a'] = word;
                s.insert({word, c});
            }
            else {
                if (r[c - 'a'] != word) {
                    return false;
                }
                if ((it == s.end()) || (it->second != c)) {
                    return false;
                }
            }

            while ((j < str.size()) && (str[j] == ' ')) {
                j++;
            }

            i = j;
        }

        return i == str.size();
    }
};
