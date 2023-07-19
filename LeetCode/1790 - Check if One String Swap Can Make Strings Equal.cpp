class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int j = -1;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                if (j == -1) {
                    j = i;
                } else if (j == -2) {
                    return false;
                } else {
                    if (s1[i] != s2[j] || s1[j] != s2[i]) {
                        return false;
                    }
                    j = -2;
                }
            }
        }
        return j < 0;
    }
};