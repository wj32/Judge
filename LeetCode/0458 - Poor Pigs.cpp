class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        const int t = minutesToTest / minutesToDie;
        // Split n buckets into d dimensions; then:
        // n^(1/d) <= t+1
        // d >= log(n)/log(t+1)
        return static_cast<int>(ceil(log(buckets) / log(t + 1)));
    }
};
