class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> low(arr.size());
        low[arr.size() - 1] = numeric_limits<int>::max();
        for (int i = arr.size() - 2; i >= 0; i--) {
            low[i] = min(low[i + 1], arr[i + 1]);
        }

        int high = numeric_limits<int>::min();
        int chunks = 0;
        for (int i = 0; i < arr.size(); i++) {
            high = max(high, arr[i]);
            if (high <= low[i]) {
                chunks++;
            }
        }
        return chunks;
    }
};
