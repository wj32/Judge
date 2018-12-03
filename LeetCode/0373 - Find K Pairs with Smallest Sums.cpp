class Solution {
public:
    struct Element {
        int sum;
        int index1;
        int index2;
    };

    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if ((nums1.size() == 0) || (nums2.size() == 0)) {
            return {};
        }
        vector<pair<int, int>> r;
        const auto cmp = [&](const Element& a, const Element& b) {
            return a.sum > b.sum;
        };
        priority_queue<Element, vector<Element>, decltype(cmp)> q(cmp);
        q.push({nums1[0] + nums2[0], 0, 0});
        while (!q.empty()) {
            const auto t = q.top();
            q.pop();

            r.push_back({nums1[t.index1], nums2[t.index2]});
            if (r.size() == k) {
                break;
            }

            if ((t.index2 == 0) && (t.index1 + 1 < nums1.size())) {
                q.push({nums1[t.index1 + 1] + nums2[0], t.index1 + 1, 0});
            }
            if (t.index2 + 1 < nums2.size()) {
                q.push({nums1[t.index1] + nums2[t.index2 + 1], t.index1, t.index2 + 1});
            }
        }
        return r;
    }
};
