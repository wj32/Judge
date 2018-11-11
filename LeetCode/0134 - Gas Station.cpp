class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const auto n = static_cast<int>(gas.size());
        int i = 0;
        int j = 0;
        int g = 0;

        while (true) {
            const int x = gas[j] - cost[j];
            if (g + x >= 0) {
                g = g + x;
                j = (j + 1) % n;
                if (j == i) {
                    return i;
                }
            }
            else {
                if (i != j) {
                    const int y = gas[i] - cost[i];
                    g = g - y;
                }
                else {
                    j = (j + 1) % n;
                }

                i = (i + 1) % n;
                if (i == 0) {
                    return -1;
                }
            }
        }
    }
};
