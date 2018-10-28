class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int d = static_cast<int>(floor(log10(x))) + 1;

        for (int i = 0; i < d / 2; i++) {
            int sel1 = static_cast<int>(pow(10, i));
            int sel2 = static_cast<int>(pow(10, d - 1 - i));

            if (((x / sel1) % 10) != ((x / sel2) % 10)) {
                return false;
            }
        }

        return true;
    }
};
