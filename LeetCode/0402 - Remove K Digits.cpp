class Solution {
public:
    string removeKdigits(string num, int k) {
        int i = 0;
        while (k != 0) {
            while ((i + 1 < num.size()) && (num[i] <= num[i + 1])) {
                i++;
            }
            num.erase(i, 1);
            if (i != 0) {
                i--;
            }
            k--;

            int j = 0;
            while ((j < num.size()) && (num[j] == '0')) {
                j++;
            }
            num.erase(0, j);
        }
        if (num.empty()) {
            num = "0";
        }
        return num;
    }
};
