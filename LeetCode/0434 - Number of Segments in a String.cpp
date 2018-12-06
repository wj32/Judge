class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        for (int i = 1; i < s.size(); i++) {
            if ((s[i - 1] != ' ') && (s[i] == ' ')) {
                count++;
            }
        }
        if (!s.empty() && (s[s.size() - 1] != ' ')) {
            count++;
        }
        return count;
    }
};
