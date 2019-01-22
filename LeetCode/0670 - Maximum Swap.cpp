class Solution {
public:
    int maximumSwap(int num) {
        auto s = to_string(num);

        auto t = s;
        sort(t.begin(), t.end(), greater<char>());

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) {
                swap(s[i], s[s.rfind(t[i])]);
                break;
            }
        }

        return stoi(s);
    }
};
