class Solution {
public:
    int lengthLongestPath(string input) {
        stack<int> s;
        int maxLength = 0;

        int index = 0;
        while (index < input.size()) {
            int level = 0;
            while ((index < input.size()) && (input[index] == '\t')) {
                level++;
                index++;
            }

            while (s.size() > level) {
                s.pop();
            }

            int endIndex = index;
            bool file = false;
            while ((endIndex < input.size()) && (input[endIndex] != '\n')) {
                if (input[endIndex] == '.') {
                    file = true;
                }
                endIndex++;
            }
            const int nameLength = endIndex - index;
            const int totalLength = s.empty() ? nameLength : (s.top() + 1 + nameLength);

            if (file) {
                maxLength = max(maxLength, totalLength);
            }
            else {
                s.push(totalLength);
            }

            index = endIndex + 1;
        }

        return maxLength;
    }
};
