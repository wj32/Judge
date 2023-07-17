class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            const auto v = parse(s[i]);
            result += i + 1 < s.size() && v < parse(s[i + 1]) ? -v : v;
        }
        return result;
    }

private:
    static constexpr std::array<int, 26> TABLE = []() constexpr {
        std::array<int, 26> table{};
        table['I' - 'A'] = 1;
        table['V' - 'A'] = 5;
        table['X' - 'A'] = 10;
        table['L' - 'A'] = 50;
        table['C' - 'A'] = 100;
        table['D' - 'A'] = 500;
        table['M' - 'A'] = 1000;
        return table;
    }();

    int parse(char c) const {
        return TABLE[c - 'A'];
    }
};