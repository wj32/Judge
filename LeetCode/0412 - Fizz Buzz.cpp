class Solution {
public:
    vector<string> fizzBuzz(int n) {
        const string fizz = "Fizz";
        const string buzz = "Buzz";
        const string fizzBuzz = "FizzBuzz";
        vector<string> r(n);
        for (int k = 1; k <= n; k++) {
            if ((k % 3) == 0) {
                if ((k % 5) == 0) {
                    r[k - 1] = fizzBuzz;
                }
                else {
                    r[k - 1] = fizz;
                }
            }
            else if ((k % 5) == 0) {
                r[k - 1] = buzz;
            }
            else {
                r[k - 1] = to_string(k);
            }
        }
        return r;
    }
};
