class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> lines;
        int wordIndex = 0;
        while (wordIndex < words.size()) {
            int wordCount = 1;
            int charCount = words[wordIndex].size();
            for (; wordIndex + wordCount < words.size() && charCount + words[wordIndex + wordCount].size() + wordCount <= maxWidth; ++wordCount) {
                charCount += words[wordIndex + wordCount].size();
            }
            string line;
            line.reserve(maxWidth);
            if (wordIndex + wordCount < words.size()) {
                const auto spaceCountBase = wordCount > 1 ? (maxWidth - charCount) / (wordCount - 1) : 0;
                auto spaceCountRemainder = wordCount > 1 ? (maxWidth - charCount) % (wordCount - 1) : 0;
                for (; wordCount > 0; --wordCount) {
                    if (!line.empty()) {
                        const auto extra = std::min(spaceCountRemainder, 1);
                        line.append(spaceCountBase + extra, ' ');
                        spaceCountRemainder -= extra;
                    }
                    line += words[wordIndex];
                    ++wordIndex;
                }
            } else {
                // Special case for last line
                for (; wordCount > 0; --wordCount) {
                    if (!line.empty()) {
                        line += ' ';
                    }
                    line += words[wordIndex];
                    ++wordIndex;
                }
            }
            if (line.size() < maxWidth) {
                line.append(maxWidth - line.size(), ' ');
            }
            lines.push_back(std::move(line));
        }
        return lines;
    }
};