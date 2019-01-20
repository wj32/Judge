class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        struct Node {
            bool end;
            array<Node*, 26> children;
        };

        const auto root = new Node{false, {}};
        for (const auto& s : dict) {
            auto node = root;
            for (const char c : s) {
                const auto child = &node->children[c - 'a'];
                if (*child == nullptr) {
                    *child = new Node{false, {}};
                }
                node = *child;
            }
            node->end = true;
        }

        string result;
        result.reserve(sentence.size());

        size_t i = 0;
        while (i < sentence.size()) {
            size_t j = i;
            while ((j < sentence.size()) && (sentence[j] >= 'a') && (sentence[j] <= 'z')) {
                j++;
            }

            auto node = root;
            for (size_t k = i; k < j; k++) {
                if (node != nullptr) {
                    if (node->end) {
                        break;
                    }
                    node = node->children[sentence[k] - 'a'];
                }
                result.append(1, sentence[k]);
            }

            if (j < sentence.size()) {
                result.append(1, sentence[j]);
            }
            i = j + 1;
        }

        return result;
    }
};
