class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) {
            return true;
        }
        int i = 0;
        while (i < flowerbed.size()) {
            if ((i + 1 < flowerbed.size()) && (flowerbed[i + 1] == 1)) {
                i += 3;
            }
            else if (flowerbed[i] == 1) {
                i += 2;
            }
            else if ((i - 1 >= 0) && (flowerbed[i - 1] == 1)) {
                i += 1;
            }
            else {
                flowerbed[i] = 1;
                n--;
                if (n == 0) {
                    return true;
                }
            }
        }
        return false;
    }
};
