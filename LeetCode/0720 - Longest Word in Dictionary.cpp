class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), [&](const auto& a, const auto& b) {
            return a.size() < b.size();
        });

        unordered_set<string> s{""};
        unordered_set<string> t;
        int wordIndex = 0;
        while (wordIndex < words.size()) {
            const auto size = words[wordIndex].size();
            while ((wordIndex < words.size()) && (words[wordIndex].size() == size)) {
                const auto& word = words[wordIndex];
                if (s.find(word.substr(0, word.size() - 1)) != s.end()) {
                    t.insert(word);
                }
                wordIndex++;
            }

            if (t.empty()) {
                break;
            }

            s.clear();
            swap(s, t);
        }

        return *min_element(s.begin(), s.end());
    }
};
