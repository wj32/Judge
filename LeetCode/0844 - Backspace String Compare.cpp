class Solution {
public:
    bool backspaceCompare(string S, string T) {
        size_t i = S.size();
        size_t j = T.size();

        while (true) {
            const auto process = [&](const string& s, size_t& i) {
                size_t b = 0;
                while ((i != 0) && ((b != 0) || (s[i - 1] == '#'))) {
                    if (s[i - 1] == '#') {
                        b++;
                    }
                    else {
                        b--;
                    }
                    i--;
                }
            };

            process(S, i);
            process(T, j);

            if ((i == 0) || (j == 0)) {
                return i == j;
            }

            if (S[i - 1] != T[j - 1]) {
                return false;
            }

            i--;
            j--;
        }
    }
};
