class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> r;

        sort(buildings.begin(), buildings.end(), [&](const auto& a, const auto& b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            }
            return a[2] > b[2];
        });

        map<int, const vector<int>*> m;
        int height = 0;

        const auto close = [&](int position) {
            auto it = m.begin();
            while ((it != m.end()) && ((position == -1) || (it->first < position))) {
                const int x = it->first;
                it = m.erase(it);
                height = (it != m.end()) ? (*it->second)[2] : 0;
                r.push_back({x, height});
            }
        };

        for (const auto& building : buildings) {
            close(building[0]);

            if (building[2] > height) {
                height = building[2];
                r.push_back({building[0], height});
            }

            // Invariant: Each building B in m ends at or after the start of the current building,
            // and B's height is greater than the height of the next building in m (sorted by end
            // point). No two buildings in m have the same end point.
            const auto it = m.upper_bound(building[1]);
            if ((it == m.end()) || ((*it->second)[2] < building[2])) {
                while (it != m.begin()) {
                    const auto itp = prev(it);
                    if ((*itp->second)[2] > building[2]) {
                        break;
                    }
                    m.erase(itp);
                }
                m.insert(it, {building[1], &building});
            }
        }

        close(-1);

        return r;
    }
};
