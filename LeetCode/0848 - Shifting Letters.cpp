class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        long long shift = 0;
        for (int i = S.size() - 1; i >= 0; i--) {
            shift += shifts[i];
            S[i] = static_cast<char>('a' + (((S[i] - 'a') + shift) % 26));
        }
        return S;
    }
};
