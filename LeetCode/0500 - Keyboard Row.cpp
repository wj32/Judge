class Solution {
public:
    const int charMap[26] = {0x2, 0x4, 0x4, 0x2, 0x1, 0x2, 0x2, 0x2, 0x1, 0x2, 0x2, 0x2, 0x4, 0x4, 0x1, 0x1, 0x1, 0x1, 0x2, 0x1, 0x1, 0x4, 0x1, 0x4, 0x1, 0x4};

    vector<string> findWords(vector<string>& words) {
        vector<string> r;
        for (const auto& word : words) {
            int mask = 0x7;
            for (const auto c : word) {
                mask &= charMap[tolower(c) - 'a'];
                if (mask == 0) {
                    break;
                }
            }
            if (mask != 0) {
                r.push_back(word);
            }
        }
        return r;
    }
};
