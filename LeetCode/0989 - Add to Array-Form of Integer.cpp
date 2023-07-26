class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int i = num.size() - 1;
        int carry = 0;
        while (k != 0 || carry != 0) {
            const auto digit = k % 10;
            k /= 10;
            auto& output = i >= 0 ? num[i] : *num.insert(num.begin(), 0);
            output += digit + carry;
            if (output >= 10) {
                output -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            --i;
        }
        return move(num);
    }
};