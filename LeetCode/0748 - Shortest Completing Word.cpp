class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        array<int, 26> plateCounts{};
        for (const char c : licensePlate) {
            if ((c >= 'a') && (c <= 'z')) {
                plateCounts[c - 'a']++;
            }
            else if ((c >= 'A') && (c <= 'Z')) {
                plateCounts[c - 'A']++;
            }
        }

        int minimumSize = numeric_limits<int>::max();
        const string* minimumSizeWord = nullptr;

        for (const auto& word : words) {
            array<int, 26> wordCounts{};
            for (const char c : word) {
                wordCounts[c - 'a']++;
            }

            bool complete = true;
            for (int i = 0; i < 26; i++) {
                if (wordCounts[i] < plateCounts[i]) {
                    complete = false;
                    break;
                }
            }

            if (complete && (minimumSize > word.size())) {
                minimumSize = word.size();
                minimumSizeWord = &word;
            }
        }

        return *minimumSizeWord;
    }
};
