class Solution {
public:
    struct ComplexInt {
        int x;
        int y;
    };

    ComplexInt mul(ComplexInt a, ComplexInt b) {
        return {(a.x * b.x) - (a.y * b.y), (a.x * b.y) + (a.y * b.x)};
    }

    ComplexInt parse(string s) {
        const auto plusIndex = s.find('+');
        assert(plusIndex != string::npos);
        assert(s.back() == 'i');
        return {stoi(s.substr(0, plusIndex)), stoi(s.substr(plusIndex + 1, s.size() - plusIndex - 2))};
    }

    string toString(ComplexInt a) {
        return to_string(a.x) + "+" + to_string(a.y) + "i";
    }

    string complexNumberMultiply(string a, string b) {
        return toString(mul(parse(a), parse(b)));
    }
};
