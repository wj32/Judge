class Solution {
public:
    string solveEquation(string equation) {
        struct {
            int a;
            int b;
        } linear = {0, 0};
        struct {
            bool present;
            int sign;
            int magnitude;
        } number;
        const decltype(number) numberDefault = {false, 1, 0};
        bool rhs = false;

        number = numberDefault;

        for (int i = 0; i <= equation.size(); i++) {
            const char c = (i < equation.size()) ? equation[i] : '\0';

            if ((c >= '0') && (c <= '9')) {
                number.magnitude *= 10;
                number.magnitude += c - '0';
                number.present = true;
            }
            else {
                if ((c == 'x') || number.present) {
                    const int sign = (rhs ? -1 : 1) * number.sign;
                    if (c == 'x') {
                        linear.a += sign * (number.present ? number.magnitude : 1);
                    }
                    else {
                        linear.b += sign * number.magnitude;
                    }
                    number = numberDefault;
                }

                if (c == '-') {
                    number.sign = -number.sign;
                }
                else if (c == '=') {
                    rhs = true;
                }
            }
        }

        if (linear.a == 0) {
            return (linear.b == 0) ? "Infinite solutions" : "No solution";
        }
        else {
            return "x=" + to_string(-linear.b / linear.a);
        }
    }
};
