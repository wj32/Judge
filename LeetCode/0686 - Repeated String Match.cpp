class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int times = (B.size() + A.size() - 1) / A.size();

        string repeated;
        repeated.reserve(times * A.size());
        for (int i = 0; i < times; i++) {
            repeated.append(A);
        }

        if (repeated.find(B) != string::npos) {
            return times;
        }

        repeated.append(A);
        if (repeated.find(B) != string::npos) {
            return times + 1;
        }

        return -1;
    }
};
