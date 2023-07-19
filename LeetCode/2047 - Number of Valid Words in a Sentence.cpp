class Solution {
public:
    int countValidWords(string sentence) {
        int count = 0;
        for (size_t i = 0; i < sentence.size(); ) {
            size_t j = i;
            while (j < sentence.size() && sentence[j] != ' ') {
                ++j;
            }
            count += isValidWord(string_view(sentence).substr(i, j - i));
            i = j + 1;
        }
        return count;
    }

    bool isValidWord(string_view s) {
        if (s.empty()) {
            return false;
        }
        bool hyphen = false;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                return false;
            } else if (s[i] == '-') {
                if (hyphen || i == 0 || i == s.size() - 1 ||
                    s[i - 1] < 'a' || s[i - 1] > 'z' ||
                    s[i + 1] < 'a' || s[i + 1] > 'z') {
                    return false;
                }
                hyphen = true;
            } else if (s[i] < 'a' || s[i] > 'z') {
                if (i != s.size() - 1) {
                    return false;
                }
            }
        }
        return true;
    }
};