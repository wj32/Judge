class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        multiset<pair<string, string>> nodes(tickets.begin(), tickets.end());
        vector<string> r;
        stack<string> s;
        s.push("JFK");
        while (!s.empty()) {
            const auto it = nodes.lower_bound({s.top(), ""});
            if ((it != nodes.end()) && (it->first == s.top())) {
                s.push(it->second);
                nodes.erase(it);
            }
            else {
                r.push_back(s.top());
                s.pop();
            }
        }
        reverse(r.begin(), r.end());
        return r;
    }
};
