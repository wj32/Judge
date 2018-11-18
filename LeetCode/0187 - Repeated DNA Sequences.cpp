class Solution {
public:
    struct Node {
        array<Node*, 4> children;
        size_t index;
    };

    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> r;

        array<unsigned char, 26> alphaToType = {};
        alphaToType['A' - 'A'] = 0;
        alphaToType['C' - 'A'] = 1;
        alphaToType['G' - 'A'] = 2;
        alphaToType['T' - 'A'] = 3;

        Node root = {};

        // Special states
        Node end = {};
        Node added = {};

        array<Node*, 9> positions = {};
        size_t base = 0;

        for (size_t i = 0; i < s.size(); i++) {
            const auto type = alphaToType[s[i] - 'A'];

            if (positions[base] != nullptr) {
                const auto position = positions[base];
                const auto child = &position->children[type];
                if (*child == nullptr) {
                    *child = &end;
                }
                else if (*child == &end) {
                    r.push_back(s.substr(position->index - 9, 9) + s[i]);
                    *child = &added;
                }
            }

            positions[base] = &root;
            base = (base + 1) % positions.size();

            for (size_t j = 0; j < positions.size(); j++) {
                const auto positionSlot = (base + j) % positions.size();
                const auto position = positions[positionSlot];
                if (position != nullptr) {
                    if (position->children[type] == nullptr) {
                        const auto newNode = new Node{{}, i + 1};
                        position->children[type] = newNode;
                    }
                    positions[positionSlot] = position->children[type];
                }
            }
        }

        return r;
    }
};
