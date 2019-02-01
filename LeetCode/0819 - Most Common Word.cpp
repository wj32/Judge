class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);

        map<string, int> wordCounts;
        size_t i = 0;
        while (i < paragraph.size()) {
            size_t j = i;
            while ((j < paragraph.size()) && isalpha(paragraph[j])) {
                j++;
            }

            if (j != i) {
                wordCounts[paragraph.substr(i, j - i)]++;
            }

            i = j + 1;
        }

        for (const auto& word : banned) {
            wordCounts.erase(word);
        }

        int maxCount = 0;
        string maxCountWord;

        for (const auto& p : wordCounts) {
            if (maxCount < p.second) {
                maxCount = p.second;
                maxCountWord = p.first;
            }
        }

        return maxCountWord;
    }
};
