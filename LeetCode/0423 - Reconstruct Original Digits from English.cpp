class Solution {
public:

    string originalDigits(string s) {
        array<int, 26> a{};
        for (const char c : s) {
            a[c - 'a']++;
        }

        struct Digit {
            char unique;
            string chars;
            int digit;
            vector<int> overlaps;
        };
        vector<Digit> v{
            {'z', "zero", 0, {}},
            {'w', "two", 2, {}},
            {'u', "four", 4, {}},
            {'x', "six", 6, {}},
            {'o', "one", 1, {0, 2, 4}},
            {'r', "three", 3, {0, 4}},
            {'f', "five", 5, {4}},
            {'s', "seven", 7, {6}},
            {'t', "eight", 8, {2, 3}},
            {'i', "nine", 9, {5, 6, 8}}
        };

        array<int, 10> d{};
        for (const auto& t : v) {
            d[t.digit] = a[t.unique - 'a'];
            for (const auto overlap : t.overlaps) {
                d[t.digit] -= d[overlap];
            }
        }

        string r;
        for (int i = 0; i < 10; i++) {
            r.append(d[i], '0' + i);
        }
        return r;
    }

// zero
// one
// two
// three
// four
// five
// six
// seven
// eight
// nine
//
// e 1 1   2   1   2 1 1
// f         1 1
// g                 1
// h       1         1
// i           1 1   1 1
// n   1           1   2
// o 1 1 1   1
// r 1     1 1
// s             1 1
// t     1 1         1
// u         1
// v           1   1
// w     1
// x             1
// z 1
//
// 1st round:
// * zero
// * two
// * four
// * six
//
// e   1   2   1   2 1 1
// f           1
// g                 1
// h       1         1
// i           1     1 1
// n   1           1   2
// o   1
// r       1
// s               1
// t       1         1
// u
// v           1   1
// w
// x
// z
//
// 2nd round:
// * one
// * three
// * five
// * seven
//
// e                 1 1
// f
// g                 1
// h                 1
// i                 1 1
// n                   2
// o
// r
// s
// t                 1
// u
// v
// w
// x
// z
//
// 3rd round:
// * eight
// * nine
//

};
