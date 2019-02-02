class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        const auto cmp = [&](const pair<int, int>& a, const pair<int, int>& b) {
            return A[a.first] * A[b.second] > A[b.first] * A[a.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);

        q.push({0, A.size() - 1});

        while (K > 1) {
            const auto t = q.top();
            q.pop();

            if ((t.first == 0) && (t.second > 0)) {
                q.push({0, t.second - 1});
            }

            if (t.first < t.second - 1) {
                q.push({t.first + 1, t.second});
            }

            K--;
        }

        return {A[q.top().first], A[q.top().second]};
    }
};
