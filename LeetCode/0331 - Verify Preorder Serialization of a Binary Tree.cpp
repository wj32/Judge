class Solution {
public:
    bool recurse(const string& s, size_t* index) {
        if (*index == s.size()) {
            return false;
        }

        const bool empty = (s[*index] == '#');

        while ((*index < s.size()) && (s[*index] != ',')) {
            (*index)++;
        }
        if (*index < s.size()) {
            (*index)++;
        }

        if (!empty) {
            if (!recurse(s, index)) {
                return false;
            }
            if (!recurse(s, index)) {
                return false;
            }
        }

        return true;
    }

    bool isValidSerialization(string preorder) {
        size_t index = 0;
        if (!recurse(preorder, &index)) {
            return false;
        }
        return index == preorder.size();
    }
};
