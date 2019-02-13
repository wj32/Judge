class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int diff = accumulate(B.begin(), B.end(), 0) - accumulate(A.begin(), A.end(), 0);
        assert((diff % 2) == 0);
        diff /= 2;

        bool swapped = false;
        if (diff < 0) {
            diff = -diff;
            swap(A, B);
            swapped = true;
        }

        int i = 0;
        for (const int x : A) {
            while ((i < B.size()) && (B[i] < x + diff)) {
                i++;
            }
            if (i >= B.size()) {
                break;
            }
            if (B[i] == x + diff) {
                vector<int> r{x, B[i]};
                if (swapped) {
                    swap(r[0], r[1]);
                }
                return r;
            }
        }

        return {};
    }
};
