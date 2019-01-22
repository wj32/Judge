class Solution {
public:
    int flipLights(int n, int m) {
        return "1111122213441478"[(min(n, 3) * 4) + min(m, 3)] - '0';
    }
};
