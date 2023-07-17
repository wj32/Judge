class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        const auto stride = numRows * 2 - 2;
        string result;
        result.reserve(s.size());
        for (int row = 0; row < numRows; ++row) {
            for (int b = 0; b < s.size(); b += stride) {
                const auto i = b + row;
                const auto j = b + stride - row;
                if (i < s.size()) {
                    result += s[i];
                }
                if (row != 0 && row != numRows - 1 && j < s.size()) {
                    result += s[j];
                }
            }
        }
        return result;
    }
};