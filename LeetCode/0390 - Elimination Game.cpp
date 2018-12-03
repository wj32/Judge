class Solution {
public:
    int lastRemaining(int n) {
        // Let f(n)=f(1,...,n) and b(n)=b(1,...,n) be the last number remaining when removing forward and backward, respectively. Then:
        //
        // f(1) = b(1) = 1
        //
        // f(2k) = f(1,2,...,2k-1,2k) = b(2,4,...,2k) = 2b(k)
        // f(2k+1) = f(1,2,...,2k-1,2k,2k+1) = b(2,4,...,2k) = 2b(k)
        //
        // b(2k) = b(1,2,...,2k-1,2k) = f(1,3,...,2k-1) = f(2,4,...,2k)-1 = 2f(k)-1
        // b(2k+1) = b(1,2,...,2k-1,2k,2k+1) = f(2,4,...,2k) = 2f(k)
        //
        // f(4k) = f(4k+1) = 4f(k)-2
        // f(4k+2) = f(4k+3) = 4f(k)

        if (n < 4) {
            return (n == 1) ? 1 : 2;
        }
        else {
            return (lastRemaining(n / 4) * 4) - (~n & 2);
        }
    }
};
