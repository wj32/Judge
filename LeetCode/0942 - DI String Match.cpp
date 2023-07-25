class Solution {
public:
    vector<int> diStringMatch(string s) {
        int i = 0;
        int d = s.size();
        vector<int> r;
        for (const auto c : s) {
            if (c == 'I') {
                r.push_back(i++);
            } else {
                r.push_back(d--);
            }
        }
        assert(i == d);
        r.push_back(i);
        return r;
    }
};