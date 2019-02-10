class Solution {
public:
    bool recurse(const string& s, size_t index, vector<int>& numbers) {
        const auto isFibonacci = [&]() {
            return numbers[numbers.size() - 1] ==
                   static_cast<long long>(numbers[numbers.size() - 2]) + numbers[numbers.size() - 3];
        };
        const auto isSubFibonacci = [&]() {
            return numbers[numbers.size() - 1] <=
                   static_cast<long long>(numbers[numbers.size() - 2]) + numbers[numbers.size() - 3];
        };

        if (index == s.size()) {
            return (numbers.size() >= 3) && isFibonacci();
        }

        if (!numbers.empty() && (numbers.back() != 0)) {
            const auto newNumber = (static_cast<long long>(numbers.back()) * 10) + (s[index] - '0');
            if (newNumber <= numeric_limits<int>::max()) {
                int number = newNumber;
                swap(numbers.back(), number);
                if (((numbers.size() < 3) || isSubFibonacci()) && recurse(s, index + 1, numbers)) {
                    return true;
                }
                swap(numbers.back(), number);
            }
        }

        if ((numbers.size() < 3) || isFibonacci()) {
            numbers.push_back(s[index] - '0');
            if (recurse(s, index + 1, numbers)) {
                return true;
            }
            numbers.pop_back();
        }

        return false;
    }

    vector<int> splitIntoFibonacci(string S) {
        vector<int> numbers;
        recurse(S, 0, numbers);
        return numbers;
    }
};
