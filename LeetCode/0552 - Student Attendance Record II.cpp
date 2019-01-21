class Solution {
public:
    const int prime = 1000000007;

    struct Mat6 {
        int m[6][6];
    };

    const Mat6 identityMatrix = {
        {{1, 0, 0, 0, 0, 0},
         {0, 1, 0, 0, 0, 0},
         {0, 0, 1, 0, 0, 0},
         {0, 0, 0, 1, 0, 0},
         {0, 0, 0, 0, 1, 0},
         {0, 0, 0, 0, 0, 1}}
    };

    const Mat6 recurrenceMatrix = {
        {{1, 1, 1, 1, 1, 1},
         {1, 0, 0, 0, 0, 0},
         {0, 1, 0, 0, 0, 0},
         {0, 0, 0, 1, 1, 1},
         {0, 0, 0, 1, 0, 0},
         {0, 0, 0, 0, 1, 0}}
    };

    Mat6 mul(const Mat6& a, const Mat6& b) {
        Mat6 c;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                long long x = 0;
                for (int k = 0; k < 6; k++) {
                    x += (static_cast<long long>(a.m[i][k]) * b.m[k][j]) % prime;
                }
                c.m[i][j] = static_cast<int>(x % prime);
            }
        }
        return c;
    }

    void pow(Mat6& a, int n) {
        auto r = identityMatrix;
        while (n != 0) {
            if ((n % 2) == 0) {
                a = mul(a, a);
                n /= 2;
            }
            else {
                r = mul(r, a);
                n--;
            }
        }
        a = r;
    }

    int checkRecord(int n) {
        auto a = recurrenceMatrix;
        pow(a, n + 1);
        return a.m[0][3];
    }
};
