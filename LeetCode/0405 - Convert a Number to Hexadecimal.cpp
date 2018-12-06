class Solution {
public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }
        auto u = static_cast<unsigned int>(num);
        string s;
        while (u != 0) {
            s.append(1, "0123456789abcdef"[u % 16]);
            u /= 16;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
