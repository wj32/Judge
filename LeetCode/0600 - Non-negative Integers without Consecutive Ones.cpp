class Solution {
public:
    int findIntegers(int num) {
        // even[i] is the number of even integers with bit i set that contain no consecutive ones.
        // odd[i] is the number of odd integers with bit i set that contain no consecutive ones.
        array<int, 31> even;
        array<int, 31> odd;
        even[0] = 0;
        odd[0] = 1;
        for (int i = 1; i < 31; i++) {
            even[i] = even[i - 1] + odd[i - 1];
            odd[i] = even[i - 1];
        }

        // acc[i] is the number of integers less than 2^i that contain no consecutive ones.
        array<int, 32> acc;
        acc[0] = 1;
        for (int i = 1; i < 32; i++) {
            acc[i] = acc[i - 1] + even[i - 1] + odd[i - 1];
        }

        num++;

        int sum = 0;
        for (int i = 30; i >= 0; i--) {
            if ((num & (1 << i)) != 0) {
                sum += acc[i];
                if ((num & (1 << (i + 1))) != 0) {
                    break;
                }
            }
        }
        return sum;
    }
};
