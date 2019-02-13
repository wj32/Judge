class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> t;
        t.push(0);
        for (const auto c : S) {
            if (c == '(') {
                t.push(0);
            }
            else {
                const auto x = t.top();
                t.pop();
                t.top() += (x != 0) ? (x * 2) : 1;
            }
        }
        const auto x = t.top();
        t.pop();
        assert(t.empty());
        return x;
    }
};
