class Solution {
public:
    void printTable() {
        int group = 1;
        long long n = 9;
        long long i = 1;
        while (i <= numeric_limits<int>::max()) {
            cout << i << ", ";
            i += n * group;
            group++;
            n *= 10;
        }
    }

    const int table[9] = { 1, 10, 190, 2890, 38890, 488890, 5888890, 68888890, 788888890 };
    const int powers[9] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000 };

    int findNthDigit(int n) {
        const int group = upper_bound(table, table + (sizeof(table) / sizeof(*table)), n) - table;
        const int offset = n - table[group - 1];
        const int base = powers[group - 1];
        const int selector = powers[group - 1 - (offset % group)];
        return ((base + (offset / group)) / selector) % 10;
    }
};
