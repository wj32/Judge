class Solution {
public:
    bool recurse(const string& bottom, string& current, int index, map<pair<char, char>, int>& allowed) {
        if (bottom.size() == 1) {
            return true;
        }

        if (index == current.size()) {
            string newCurrent(current.size() - 1, ' ');
            return recurse(current, newCurrent, 0, allowed);
        }
        else {
            bool result = false;

            const auto it = allowed.find({bottom[index], bottom[index + 1]});
            if (it == allowed.end()) {
                return false;
            }

            for (char c = 'A'; c <= 'G'; c++) {
                if ((it->second & (1 << (c - 'A'))) != 0) {
                    current[index] = c;
                    if (recurse(bottom, current, index + 1, allowed)) {
                        return true;
                    }
                }
            }

            return false;
        }
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        map<pair<char, char>, int> allowedMap;
        for (const auto& triple : allowed) {
            const auto it = allowedMap.insert({{triple[0], triple[1]}, 0}).first;
            it->second |= 1 << (triple[2] - 'A');
        }
        string current(bottom.size() - 1, ' ');
        return recurse(bottom, current, 0, allowedMap);
    }
};
