class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for (const auto& token : tokens) {
            function<int(int, int)> f;
            if (token == "+") {
                f = [&](int x, int y) { return x + y; };
            }
            else if (token == "-") {
                f = [&](int x, int y) { return x - y; };
            }
            else if (token == "*") {
                f = [&](int x, int y) { return x * y; };
            }
            else if (token == "/") {
                f = [&](int x, int y) { return x / y; };
            }

            if (f) {
                const auto x = s.top();
                s.pop();
                const auto y = s.top();
                s.pop();
                s.push(f(y, x));
            }
            else {
                s.push(stoi(token));
            }
        }

        return s.top();
    }
};
