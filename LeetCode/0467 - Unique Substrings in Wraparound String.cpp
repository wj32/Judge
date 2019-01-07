class Solution {
public:
    int findSubstringInWraproundString(string p) {
        array<int, 26> counts{};
        int run = 1;
        for (int i = 0; i < p.size(); i++) {
            if ((i > 0) && ((p[i] - 'a') == ((p[i - 1] - 'a') + 1) % 26)) {
                run++;
            }
            else {
                run = 1;
            }
            const auto count = &counts[p[i] - 'a'];
            *count = max(*count, run);
        }
        return accumulate(counts.begin(), counts.end(), 0);
    }
};
