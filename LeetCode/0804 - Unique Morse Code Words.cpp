class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        const vector<string> table{".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        set<string> unique;
        for (const auto& word : words) {
            string s;
            for (const char c : word) {
                s.append(table[c - 'a']);
            }
            unique.insert(s);
        }
        return unique.size();
    }
};
