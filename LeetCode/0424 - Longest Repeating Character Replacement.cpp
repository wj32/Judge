class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<vector<pair<int, int>>> runs(26, vector<pair<int, int>>{pair<int, int>{0, 0}});
        for (int i = 0; i < s.size(); i++) {
            auto& r = runs[s[i] - 'A'];
            if ((r.size() > 1) && (r.back().second == i)) {
                r.back().second++;
            }
            else {
                r.push_back({i, i + 1});
            }
        }

        int maxLength = 0;
        for (int i = 0; i < 26; i++) {
            auto& r = runs[i];
            r.push_back({s.size(), s.size()});

            int start = 1;
            int end = 1;
            int quota = k;

            while (end < r.size() - 1) {
                while (end < r.size() - 1) {
                    const int distance = (start < end) ? (r[end].first - r[end - 1].second) : 0;
                    if (quota < distance) {
                        break;
                    }
                    end++;
                    quota -= distance;
                }
                const int beforeDistance = r[start].first - r[start - 1].second;
                const int afterDistance = r[end].first - r[end - 1].second;
                const int unusedQuota = min(quota, beforeDistance + afterDistance);
                const int length = r[end - 1].second - r[start].first + unusedQuota;
                // cout << "[" << start << ", " << end << "): " << length << endl;
                maxLength = max(maxLength, length);
                start++;
                if (start < end) {
                    quota += r[start].first - r[start - 1].second;
                }
            }
        }
        return maxLength;
    }
};
