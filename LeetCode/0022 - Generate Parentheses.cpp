class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> r;

        if (n == 0) {
            r.push_back("");
        } else {
            for (int i = 0; i < n; i++) {
                for (const auto& s : generateParenthesis(i)) {
                    for (const auto& t : generateParenthesis(n - 1 - i)) {
                        r.push_back("(" + s + ")" + t);
                    }
                }
            }
        }

        return r;
    }
};
