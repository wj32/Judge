class Solution {
public:
    vector<int> partitionLabels(string S) {
        array<int, 26> right{};
        int rightMask = 0;
        for (const char c : S) {
            const int charIndex = c - 'a';
            right[charIndex]++;
            rightMask |= 1 << charIndex;
        }

        array<int, 26> left{};
        int leftMask = 0;

        vector<int> r;
        int prevIndex = 0;

        for (int i = 0; i < S.size(); i++) {
            const int charIndex = S[i] - 'a';

            right[charIndex]--;
            if (right[charIndex] == 0) {
                rightMask &= ~(1 << charIndex);
            }

            if (left[charIndex] == 0) {
                leftMask |= 1 << charIndex;
            }
            left[charIndex]++;

            if ((leftMask & rightMask) == 0) {
                r.push_back(i + 1 - prevIndex);
                prevIndex = i + 1;
            }
        }

        return r;
    }
};
