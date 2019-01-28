class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunks = 0;
        int high = 0;
        for (int i = 0; i < arr.size(); i++) {
            high = max(high, arr[i]);
            if (i == high) {
                chunks++;
            }
        }
        return chunks;
    }
};
