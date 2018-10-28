class Solution {
public:
    int longestValidParentheses(string s) {
        int longest = 0;
        stack<int> t;

        t.push(0);

        for (char c : s) {
            if (c == '(') {
                t.push(0);
            } else {
                if (t.size() > 1) {
                    const int n = t.top();
                    t.pop();
                    t.top() += n + 2;
                    if (longest < t.top()) {
                        longest = t.top();
                    }
                } else {
                    t.top() = 0;
                }
            }
        }

        return longest;
    }
};
