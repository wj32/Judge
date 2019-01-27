class Solution {
public:
    int countBits(int x) {
        int count = 0;
        while (x != 0) {
            count++;
            x &= x - 1;
        }
        return count;
    }

    bool isPrime(int n) {
        switch (n) {
            case 2:
            case 3:
            case 5:
            case 7:
            case 11:
            case 13:
            case 17:
            case 19:
                return true;
            default:
                return false;
        }
    }

    int countPrimeSetBits(int L, int R) {
        int count = 0;
        for (int x = L; x <= R; x++) {
            if (isPrime(countBits(x))) {
                count++;
            }
        }
        return count;
    }
};
