class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        if (s.size() < 2) {
            return N;
        }

        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] > s[i + 1]) {
                fill(s.begin() + i + 1, s.end(), '9');
                s[i]--;
                for (int j = i; j >= 1; j--) {
                    if (s[j - 1] > s[j]) {
                        s[j - 1] = s[j];
                        s[j] = '9';
                    }
                }
                break;
            }
        }

        return stoi(s);
    }
};
