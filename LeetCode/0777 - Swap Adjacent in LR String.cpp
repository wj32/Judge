class Solution {
public:
    bool canTransform(string start, string end) {
        if (start.size() != end.size()) {
            return false;
        }
        const auto n = start.size();
        size_t i = 0;
        size_t j = 0;
        while (true) {
            while ((i < n) && (start[i] == 'X')) {
                i++;
            }
            while ((j < n) && (end[j] == 'X')) {
                j++;
            }

            if ((i == n) || (j == n)) {
                return i == j;
            }

            if (start[i] != end[j]) {
                return false;
            }

            if (start[i] == 'L') {
                if (i < j) {
                    return false;
                }
            }
            else {
                if (i > j) {
                    return false;
                }
            }

            i++;
            j++;
        }
    }
};
