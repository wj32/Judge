class WordFilter {
    struct SuffixNode {
        int maxWeight;
        array<SuffixNode*, 26> children;
    };

    struct PrefixNode {
        SuffixNode suffixRoot;
        array<PrefixNode*, 26> children;
    };

    PrefixNode prefixRoot{{-1, {}}, {}};

public:
    WordFilter(vector<string> words) {
        for (int i = 0; i < words.size(); i++) {
            const auto& word = words[i];
            auto prefixNode = &prefixRoot;

            const auto addSuffix = [&]() {
                auto suffixNode = &prefixNode->suffixRoot;

                for (int j = word.size() - 1; j >= 0; j--) {
                    suffixNode->maxWeight = i;

                    const auto child = &suffixNode->children[word[j] - 'a'];
                    if (*child == nullptr) {
                        *child = new SuffixNode{-1, {}};
                    }
                    suffixNode = *child;
                }

                suffixNode->maxWeight = i;
            };

            for (int j = 0; j < word.size(); j++) {
                addSuffix();

                const auto child = &prefixNode->children[word[j] - 'a'];
                if (*child == nullptr) {
                    *child = new PrefixNode{{-1, {}}, {}};
                }
                prefixNode = *child;
            }

            addSuffix();
        }
    }

    int f(string prefix, string suffix) {
        auto prefixNode = &prefixRoot;
        for (int j = 0; j < prefix.size(); j++) {
            prefixNode = prefixNode->children[prefix[j] - 'a'];
            if (prefixNode == nullptr) {
                return -1;
            }
        }

        auto suffixNode = &prefixNode->suffixRoot;
        for (int j = suffix.size() - 1; j >= 0; j--) {
            suffixNode = suffixNode->children[suffix[j] - 'a'];
            if (suffixNode == nullptr) {
                return -1;
            }
        }

        return suffixNode->maxWeight;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */
