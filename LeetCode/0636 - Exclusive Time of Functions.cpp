class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> times(n);
        stack<pair<int, int>> s;
        for (const auto& line : logs) {
            const size_t colonIndex1 = line.find(':');
            const size_t colonIndex2 = line.find(':', colonIndex1 + 1);
            const int functionId = stoi(line.substr(0, colonIndex1));
            const bool start = line.substr(colonIndex1 + 1, colonIndex2 - (colonIndex1 + 1)) == "start";
            const int timestamp = stoi(line.substr(colonIndex2 + 1));
            if (start) {
                if (!s.empty()) {
                    times[s.top().first] += timestamp - s.top().second;
                }
                s.push({functionId, timestamp});
            }
            else {
                assert(!s.empty() && (s.top().first == functionId));
                times[functionId] += timestamp + 1 - s.top().second;
                s.pop();
                if (!s.empty()) {
                    s.top().second = timestamp + 1;
                }
            }
        }
        return times;
    }
};
