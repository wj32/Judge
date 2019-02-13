class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        const auto encodeObstacle = [&](int x, int y) {
            return ((x + 30000) << 16) | (y + 30000);
        };
        unordered_set<int> obstaclesSet;
        for (const auto& p : obstacles) {
            obstaclesSet.insert(encodeObstacle(p[0], p[1]));
        }

        const vector<pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int directionIndex = 0;
        int x = 0;
        int y = 0;
        int maxDistance = 0;

        for (const auto command : commands) {
            if (command == -1) {
                directionIndex++;
                if (directionIndex == directions.size()) {
                    directionIndex -= directions.size();
                }
            }
            else if (command == -2) {
                directionIndex--;
                if (directionIndex < 0) {
                    directionIndex += directions.size();
                }
            }
            else {
                for (int i = 0; i < command; i++) {
                    const int nx = x + directions[directionIndex].first;
                    const int ny = y + directions[directionIndex].second;
                    if (obstaclesSet.find(encodeObstacle(nx, ny)) != obstaclesSet.end()) {
                        break;
                    }
                    x = nx;
                    y = ny;
                    maxDistance = max(maxDistance, (x * x) + (y * y));
                }
            }
        }

        return maxDistance;
    }
};
