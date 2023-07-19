class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        const int prime = 1000000007;
        auto candidates = nums1;
        sort(candidates.begin(), candidates.end());
        int absSumDiff = 0;
        int bestImprovement = 0;
        for (size_t i = 0; i < nums1.size(); ++i) {
            const auto absDiff = abs(nums1[i] - nums2[i]);
            absSumDiff = (absSumDiff + absDiff) % prime;
            if (absDiff <= bestImprovement) {
                continue;
            }
            const auto it = lower_bound(candidates.begin(), candidates.end(), nums2[i]);
            const auto candidate = [&] {
                if (it == candidates.begin()) {
                    return *it;
                } else if (it == candidates.end()) {
                    return *prev(it);
                }
                return abs(*it - nums2[i]) <= abs(*prev(it) - nums2[i]) ? *it : *prev(it);
            }();
            const auto improvement = absDiff - abs(candidate - nums2[i]);
            bestImprovement = max(bestImprovement, improvement);
        }
        return (absSumDiff - bestImprovement + prime) % prime;
    }
};