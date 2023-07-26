class Solution {
public:
    int recurse(const string_view bound, const string_view allowed) {
        if (bound.empty()) {
            return 1;
        }
        int result = count_if(allowed.begin(), allowed.end(), [&](const auto c) { return c < bound.front(); });
        if (result != 0) {
            for (int i = 0; i < bound.size() - 1; ++i) {
                result *= allowed.size();
            }
        }
        if (allowed.find(bound.front()) != string_view::npos) {
            result += recurse(bound.substr(1), allowed);
        }
        return result;
    }

    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string allowed;
        for (const auto& s : digits) {
            allowed += s[0];
        }
        const auto bound = to_string(n);
        // Full number of digits
        int result = recurse(bound, allowed);
        // Fewer digits
        int power = 1;
        for (int i = 0; i < bound.size() - 1; ++i) {
            power *= allowed.size();
            result += power;
        }
        return result;
    }
};