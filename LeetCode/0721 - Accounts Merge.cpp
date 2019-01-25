class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, int> emails;
        vector<pair<int, string>> groups;

        const auto findRoot = [&](int rootIndex) {
            while (rootIndex != groups[rootIndex].first) {
                const auto parentIndex = groups[rootIndex].first;
                groups[rootIndex].first = groups[parentIndex].first;
                rootIndex = parentIndex;
            }
            return rootIndex;
        };

        for (const auto& v : accounts) {
            auto groupIndex = [&] {
                for (int i = 1; i < v.size(); i++) {
                    const auto it = emails.find(v[i]);
                    if (it != emails.end()) {
                        return findRoot(it->second);
                    }
                }
                return -1;
            }();

            if (groupIndex == -1) {
                groupIndex = groups.size();
                groups.push_back({groupIndex, v[0]});
            }

            for (int i = 1; i < v.size(); i++) {
                const auto it = emails.find(v[i]);
                if (it != emails.end()) {
                    groups[findRoot(it->second)].first = groupIndex;
                }
                emails[v[i]] = groupIndex;
            }
        }

        vector<vector<string>> merged;
        unordered_map<int, int> groupMap;

        for (auto& p : emails) {
            const auto rootIndex = findRoot(p.second);
            auto it = groupMap.find(rootIndex);
            if (it == groupMap.end()) {
                it = groupMap.insert({rootIndex, merged.size()}).first;
                merged.push_back({groups[rootIndex].second});
            }
            merged[it->second].push_back(p.first);
        }

        return merged;
    }
};
