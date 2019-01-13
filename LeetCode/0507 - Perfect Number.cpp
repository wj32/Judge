class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) {
            return false;
        }
        const int limit = static_cast<int>(sqrt(num + 0.5));
        int sum = 1;
        for (int i = 2; i < limit; i++) {
            if ((num % i) == 0) {
                sum += i;
                sum += num / i;
            }
        }
        if ((limit > 1) && ((num % limit) == 0)) {
            sum += limit;
            if (num != num / limit) {
                sum += num / limit;
            }
        }
        return sum == num;
    }
};
