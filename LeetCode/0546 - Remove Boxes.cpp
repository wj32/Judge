class Solution {
public:
    int recurse(const vector<pair<int, int>>& runs, int start, int end, int left, vector<vector<vector<int>>>& cache) {
        if (start > end) {
            return left * left;
        }
        const auto cacheEntry = &cache[start][end][left];
        if (*cacheEntry == -1) {
            *cacheEntry = [&] {
                const auto run = runs[start];
                start++;
                left += run.second;
                int points = (left * left) + recurse(runs, start, end, 0, cache);
                for (int i = start + 1; i <= end; i++) {
                    if (runs[i].first == run.first) {
                        points = max(points, recurse(runs, start, i - 1, 0, cache) + recurse(runs, i, end, left, cache));
                    }
                }
                return points;
            }();
        }
        return *cacheEntry;
    }

    int removeBoxes(vector<int>& boxes) {
        vector<pair<int, int>> runs;
        runs.reserve(boxes.size());
        for (int i = 0; i < boxes.size(); i++) {
            if (!runs.empty() && (runs.back().first == boxes[i])) {
                runs.back().second++;
            }
            else {
                runs.push_back({boxes[i], 1});
            }
        }
        vector<vector<vector<int>>> cache(runs.size(), vector<vector<int>>(runs.size(), vector<int>(boxes.size(), -1)));
        return recurse(runs, 0, runs.size() - 1, 0, cache);
    }
};
