class Solution {
public:
    string reverseVowels(string s) {
        array<bool, 256> isVowel = {};
        for (const char c : {'a', 'e', 'i', 'o', 'u'}) {
            isVowel[c] = true;
            isVowel[toupper(c)] = true;
        }

        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (!isVowel[s[i]]) {
                i++;
                continue;
            }
            if (!isVowel[s[j]]) {
                j--;
                continue;
            }
            swap(s[i], s[j]);
            i++;
            j--;
        }

        return s;
    }
};
