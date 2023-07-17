class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        const auto wordSize = words[0].size();
        unordered_map<string_view, size_t> wordToIndex;
        vector<short> targetWordCounts;
        for (const auto& wordStr : words) {
            if (const auto [it, inserted] = wordToIndex.try_emplace(string_view(wordStr), targetWordCounts.size()); !inserted) {
                ++targetWordCounts[it->second];
            } else {
                targetWordCounts.push_back(1);
            }
        }
        vector<short> wordCounts;
        int matchCount;
        const auto adjust = [&](const auto i, const auto delta) {
            const auto word = string_view(s).substr(i, wordSize);
            const auto it = wordToIndex.find(word);
            if (it == wordToIndex.end()) {
                return;
            }
            auto& wordCount = wordCounts[it->second];
            if (wordCount == 0) {
                --matchCount;
            }
            wordCount += delta;
            if (wordCount == 0) {
                ++matchCount;
            }
        };
        vector<int> indices;
        for (size_t offset = 0; offset < wordSize; ++offset) {
            wordCounts = targetWordCounts;
            matchCount = 0;
            auto begin = offset;
            auto end = offset + wordSize * words.size();
            if (end > s.size()) {
                continue;
            }
            for (size_t i = begin; i < end; i += wordSize) {
                adjust(i, -1);
            }
            if (matchCount == wordCounts.size()) {
                indices.push_back(begin);
            }
            while (end + wordSize <= s.size()) {
                adjust(begin, 1);
                begin += wordSize;
                adjust(end, -1);
                end += wordSize;
                if (matchCount == wordCounts.size()) {
                    indices.push_back(begin);
                }
            }
        }
        return indices;
    }
};