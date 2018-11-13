class Solution {
public:
    int compareVersion(string version1, string version2) {
        const auto getNumber = [&](const string& s, size_t* index) {
            if (*index == s.size()) {
                return 0;
            }
            size_t indexOfDot = *index;
            while ((indexOfDot < s.size()) && (s[indexOfDot] != '.')) {
                indexOfDot++;
            }
            const auto number = stoi(s.substr(*index, indexOfDot - *index));
            *index = min(indexOfDot + 1, s.size());
            return number;
        };

        size_t index1 = 0;
        size_t index2 = 0;

        while ((index1 < version1.size()) || (index2 < version2.size())) {
            const auto number1 = getNumber(version1, &index1);
            const auto number2 = getNumber(version2, &index2);

            if (number1 < number2) {
                return -1;
            }
            else if (number1 > number2) {
                return 1;
            }
        }

        return 0;
    }
};
