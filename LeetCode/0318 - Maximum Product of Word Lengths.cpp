class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> masks(words.size());
        for (size_t i = 0; i < words.size(); i++) {
            int mask = 0;
            for (const char c : words[i]) {
                mask |= 1 << (c - 'a');
            }
            masks[i] = mask;
        }

        size_t maxValue = 0;
        for (size_t i = 0; i < words.size(); i++) {
            for (size_t j = i + 1; j < words.size(); j++) {
                if ((masks[i] & masks[j]) == 0) {
                    maxValue = max(maxValue, words[i].size() * words[j].size());
                }
            }
        }
        return maxValue;
    }
};
