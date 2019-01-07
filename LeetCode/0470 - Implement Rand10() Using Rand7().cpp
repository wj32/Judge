// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        while (true) {
            const int a = rand7() - 1;
            const int b = rand7() - 1;
            const int c = (7 * a) + b;
            if (c < 40) {
                return (c % 10) + 1;
            }
        }
    }
};
