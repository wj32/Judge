class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        const auto total = accumulate(arr.begin(), arr.end(), 0);
        if (total == 0) {
            return vector{0, 2};
        }
        if (total % 3 != 0) {
            return vector{-1, -1};
        }
        const auto partSum = total / 3;
        // 0 1 0 1 0 0 0 1 0 1 0 0 0 1 0 1 0
        //   a       b   c       d   e
        int a = 0;
        for (; a < arr.size() && arr[a] == 0; ++a) {
        }
        int b = a;
        int bt = 0;
        for (; b < arr.size() && bt < partSum; ++b) {
            bt += arr[b];
        }
        int e = arr.size();
        int et = 0;
        int trailing = 0;
        for (; e > 0 && arr[e - 1] == 0; --e) {
            ++trailing;
        }
        b += trailing;
        for (; e > 0 && et < partSum; --e) {
            et += arr[e - 1];
        }
        const int partLength = arr.size() - e;
        int d = e;
        for (; d > 0 && arr[d - 1] == 0; --d) {
        }
        d += trailing;
        int c = d - partLength;
        if (b > c ||
            d > e ||
            !std::equal(arr.begin() + a, arr.begin() + b, arr.begin() + c) ||
            !std::equal(arr.begin() + a, arr.begin() + b, arr.begin() + e)) {
            return {-1, -1};
        }
        return {b - 1, d};
    }
};