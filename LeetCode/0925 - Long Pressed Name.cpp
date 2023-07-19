class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        size_t s = 0;
        for (size_t i = 0; i < name.size(); ) {
            auto j = i;
            while (j < name.size() && name[j] == name[i]) {
                ++j;
            }
            auto t = s;
            while (t < typed.size() && typed[t] == name[i]) {
                ++t;
            }
            if (j - i > t - s) {
                return false;
            }
            i = j;
            s = t;
        }
        return s == typed.size();
    }
};