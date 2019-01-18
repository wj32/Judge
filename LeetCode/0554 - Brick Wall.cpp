class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        vector<int> indices(wall.size(), 0);

        struct Entry {
            int x;
            int row;
            int nextBrick;
        };
        const auto cmp = [&](const Entry& a, const Entry& b) {
            return a.x > b.x;
        };
        priority_queue<Entry, vector<Entry>, decltype(cmp)> q(cmp);

        for (int row = 0; row < wall.size(); row++) {
            if (wall[row].size() > 1) {
                q.push({wall[row].front(), row, 1});
            }
        }

        int maxCount = 0;
        int currentX = 0;
        int currentCount = 0;

        while (!q.empty()) {
            const auto entry = q.top();
            q.pop();

            if (entry.nextBrick + 1 < wall[entry.row].size()) {
                q.push({entry.x + wall[entry.row][entry.nextBrick], entry.row, entry.nextBrick + 1});
            }

            if (currentX != entry.x) {
                currentX = entry.x;
                currentCount = 0;
            }
            currentCount++;
            maxCount = max(maxCount, currentCount);
        }

        return wall.size() - maxCount;
    }
};
