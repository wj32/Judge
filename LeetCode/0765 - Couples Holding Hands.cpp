class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        vector<int> permutation(row.size());
        for (int i = 0; i < row.size(); i += 2) {
            permutation[row[i]] = row[i + 1];
            permutation[row[i + 1]] = row[i];
        }

        int swaps = 0;
        for (int i = 0; i < permutation.size(); i += 2) {
            if (permutation[i] != -1) {
                int cycleLength = 0;
                int j = i;
                do {
                    cycleLength++;
                    const int k = permutation[j ^ 1];
                    permutation[j] = -1;
                    permutation[j ^ 1] = -1;
                    j = k;
                } while (permutation[j] != -1);
                swaps += cycleLength - 1;
            }
        }
        return swaps;
    }
};
