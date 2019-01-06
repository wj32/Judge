class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> m;
        for (const int c : C) {
            for (const int d : D) {
                m[c + d]++;
            }
        }

        int count = 0;
        for (const int a : A) {
            for (const int b : B) {
                const auto it = m.find(-(a + b));
                if (it != m.end()) {
                    count += it->second;
                }
            }
        }
        return count;
    }
};
