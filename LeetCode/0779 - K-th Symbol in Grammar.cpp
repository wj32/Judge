class Solution {
public:
    int kthGrammar(int N, int K) {
        K--;
        int count = 0;
        while (K != 0) {
            count++;
            K &= K - 1;
        }
        return count % 2;
    }
};
