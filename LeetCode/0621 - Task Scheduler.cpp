class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) {
            return tasks.size();
        }

        array<int, 26> taskCounts{};
        for (const char c : tasks) {
            taskCounts[c - 'A']++;
        }

        priority_queue<int> pq;
        queue<pair<int, int>> uq;

        for (int i = 0; i < 26; i++) {
            if (taskCounts[i] != 0) {
                pq.push(taskCounts[i]);
            }
        }

        int time = 0;
        while (!pq.empty() || !uq.empty()) {
            while (!uq.empty() && (time - uq.front().first > n)) {
                pq.push(uq.front().second);
                uq.pop();
            }
            if (!pq.empty()) {
                auto taskCount = pq.top();
                pq.pop();

                taskCount--;
                if (taskCount != 0) {
                    uq.push({time, taskCount});
                }
            }
            time++;
        }
        return time;
    }
};
