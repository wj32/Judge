class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        const int m = A.size();
        const int n = A[0].size();
        const int highBit = 1 << (n - 1);
        vector<int> numbers(m);
        for (int i = 0; i < m; i++) {
            int number = 0;
            for (int j = 0; j < n; j++) {
                number *= 2;
                number += A[i][j];
            }
            if ((number & highBit) == 0) {
                number = ~number & ((highBit << 1) - 1);
            }
            numbers[i] = number;
        }

        int sum = accumulate(numbers.begin(), numbers.end(), 0);
        for (int j = 0; j < n - 1; j++) {
            const int bit = 1 << j;
            int count = 0;
            for (const auto number : numbers) {
                if ((number & bit) != 0) {
                    count++;
                }
            }
            if (count < (m + 1) / 2) {
                sum += (m - (count * 2)) * bit;
            }
        }
        return sum;
    }
};
