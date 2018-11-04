class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (true) {
            while ((i < j) && !isalnum(s[i])) {
                i++;
            }
            while ((i < j) && !isalnum(s[j])) {
                j--;
            }
            if (i >= j) {
                break;
            }
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};
