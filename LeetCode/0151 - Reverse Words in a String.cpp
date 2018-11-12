class Solution {
public:
    void reverseWords(string &s) {
        size_t dst = 0;
        for (const auto c : s) {
            if ((c != ' ') || ((dst != 0) && (s[dst - 1] != ' '))) {
                s[dst] = c;
                dst++;
            }
        }
        if ((dst != 0) && (s[dst - 1] == ' ')) {
            dst--;
        }
        s.resize(dst);

        const auto reverse = [&](size_t start, size_t count) {
            for (size_t i = 0; i < count / 2; i++) {
                swap(s[start + i], s[start + count - 1 - i]);
            }
        };

        reverse(0, s.size());

        for (size_t i = 0; i < s.size(); ) {
            size_t j = i;
            while ((j < s.size()) && (s[j] != ' ')) {
                j++;
            }
            reverse(i, j - i);
            i = j + 1;
        }
    }
};
