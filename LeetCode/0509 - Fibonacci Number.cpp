class Solution {
public:
    int fib(int N) {
        int x = 0;
        int y = 1;
        while (N != 0) {
            const int z = x + y;
            x = y;
            y = z;
            N--;
        }
        return x;
    }
};
