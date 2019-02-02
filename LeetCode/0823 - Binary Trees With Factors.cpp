class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        const int prime = 1000000007;
        sort(A.begin(), A.end());
        long long totalSum = 0;
        unordered_map<int, int> m;
        for (const int x : A) {
            long long sum = 1;
            for (const auto& p : m) {
                if ((x % p.first) == 0) {
                    const auto it = m.find(x / p.first);
                    if (it != m.end()) {
                        sum += (static_cast<long long>(p.second) * it->second) % prime;
                    }
                }
            }
            sum %= prime;
            m[x] = static_cast<int>(sum);
            totalSum = (totalSum + sum) % prime;
        }
        return static_cast<int>(totalSum);
    }
};
