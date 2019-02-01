class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> m;
        for (const auto& s : cpdomains) {
            const size_t indexOfSpace = s.find(' ');
            assert(indexOfSpace != string::npos);
            const int count = stoi(s.substr(0, indexOfSpace));
            size_t index = indexOfSpace;
            while (index != string::npos) {
                m[s.substr(index + 1)] += count;
                index = s.find('.', index + 1);
            }
        }

        vector<string> r;
        for (const auto& p : m) {
            r.push_back(to_string(p.second) + " " + p.first);
        }
        return r;
    }
};
