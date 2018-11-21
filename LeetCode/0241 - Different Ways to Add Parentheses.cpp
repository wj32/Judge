class Solution {
public:
    vector<int> recurse(const vector<pair<char, int>>& tokens, size_t start, size_t end) {
        if (end - start == 1) {
            return {tokens[start].second};
        }

        vector<int> r;

        for (size_t i = start + 1; i < end; i += 2) {
            function<int(int, int)> op;
            switch (tokens[i].first) {
            case '+':
                op = [&](int x, int y) { return x + y; };
                break;
            case '-':
                op = [&](int x, int y) { return x - y; };
                break;
            case '*':
                op = [&](int x, int y) { return x * y; };
                break;
            }

            const auto r1 = recurse(tokens, start, i);
            const auto r2 = recurse(tokens, i + 1, end);

            r.reserve(r.size() + (r1.size() * r2.size()));

            for (const auto& x1 : r1) {
                for (const auto& x2 : r2) {
                    r.push_back(op(x1, x2));
                }
            }
        }

        return r;
    }

    vector<int> diffWaysToCompute(string input) {
        vector<pair<char, int>> tokens;
        size_t i = 0;
        while (i < input.size()) {
            if ((input[i] >= '0') && (input[i] <= '9')) {
                int number = 0;
                while ((i < input.size()) && (input[i] >= '0') && (input[i] <= '9')) {
                    number *= 10;
                    number += input[i] - '0';
                    i++;
                }
                tokens.push_back({'\0', number});
            }
            else {
                tokens.push_back({input[i], 0});
                i++;
            }
        }
        return recurse(tokens, 0, tokens.size());
    }
};
