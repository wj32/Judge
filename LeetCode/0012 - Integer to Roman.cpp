class Solution {
public:
    string intToRoman(int num) {
        string result;
        const auto process = [&](int scale, char one, char five, char ten) {
            const auto digit = num / scale;
            if (digit == 0) {
            } else if (digit <= 3) {
                result.append(digit, one);
            } else if (digit == 4) {
                result += one;
                result += five;
            } else if (digit == 5) {
                result += five;
            } else if (digit <= 8) {
                result += five;
                result.append(digit - 5, one);
            } else if (digit == 9) {
                result += one;
                result += ten;
            }
            num -= digit * scale;
        };
        process(1000, 'M', '?', '?');
        process(100, 'C', 'D', 'M');
        process(10, 'X', 'L', 'C');
        process(1, 'I', 'V', 'X');
        return result;
    }
};