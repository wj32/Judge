class Solution {
public:
    string removeDuplicateLetters(string s) {
        array<int, 26> after = {};
        array<bool, 26> present = {};
        string r;
        for (const char c : s) {
            after[c - 'a']++;
        }
        for (const char c : s) {
            after[c - 'a']--;
            if (!present[c - 'a']) {
                while (!r.empty() && (after[r.back() - 'a'] > 0) && (r.back() > c)) {
                    present[r.back() - 'a'] = false;
                    r.pop_back();
                }
                r.push_back(c);
                present[c - 'a'] = true;
            }
        }
        return r;
    }
};
