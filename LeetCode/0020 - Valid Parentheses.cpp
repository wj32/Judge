class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        for (char c : s) {
            switch (c) {
                case '(':
                    t.push(')');
                    break;
                case '[':
                    t.push(']');
                    break;
                case '{':
                    t.push('}');
                    break;
                default:
                    if (t.empty() || (c != t.top())) {
                        return false;
                    }
                    t.pop();
                    break;
            }
        }
        return t.empty();
    }
};
