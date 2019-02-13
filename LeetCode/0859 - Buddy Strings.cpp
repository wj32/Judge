class Solution {
public:
    bool buddyStrings(string A, string B) {
        if ((A.size() < 2) || (A.size() != B.size())) {
            return false;
        }

        array<bool, 26> seen{};
        bool duplicate = false;
        int mismatch1 = -1;
        int mismatch2 = -1;

        for (int i = 0; i < A.size(); i++) {
            if (!seen[A[i] - 'a']) {
                seen[A[i] - 'a'] = true;
            }
            else {
                duplicate = true;
            }

            if (A[i] != B[i]) {
                if (mismatch1 == -1) {
                    mismatch1 = i;
                }
                else if (mismatch2 == -1) {
                    mismatch2 = i;
                }
                else {
                    return false;
                }
            }
        }

        if (mismatch1 != -1) {
            if (mismatch2 == -1) {
                return false;
            }
            return (A[mismatch1] == B[mismatch2]) && (A[mismatch2] == B[mismatch1]);
        }
        else {
            return duplicate;
        }
    }
};
