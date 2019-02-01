class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [&](const auto& a, const auto& b) {
            if (a[1] != b[1]) {
                return a[1] < b[1];
            }
            else {
                return a[0] < b[0];
            }
        });
        priority_queue<int> q;
        int end = 0;
        for (const auto& course : courses) {
            if (end + course[0] <= course[1]) {
                end += course[0];
                q.push(course[0]);
            }
            else if (!q.empty() && (q.top() > course[0])) {
                end -= q.top();
                end += course[0];
                q.pop();
                q.push(course[0]);
            }
        }
        return q.size();
    }
};
