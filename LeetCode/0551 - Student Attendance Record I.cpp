class Solution {
public:
    bool checkRecord(string s) {
        bool a = false;
        int l = 0;

        for (const char c : s) {
            if (c == 'A') {
                if (a) {
                    return false;
                }
                a = true;
            }

            if (c == 'L') {
                l++;
                if (l > 2) {
                    return false;
                }
            }
            else {
                l = 0;
            }
        }

        return true;
    }
};
