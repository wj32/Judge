class Solution {
public:
    string simplifyPath(string path) {
        deque<string> s;
        size_t i = 0;

        while (i < path.size()) {
            const auto j = [&] {
                const auto j = path.find('/', i);
                if (j != string::npos) {
                    return j;
                }
                else {
                    return path.size();
                }
            }();
            const auto t = path.substr(i, j - i);

            if (t.empty() || (t == ".")) {
                // Nothing
            }
            else if (t == "..") {
                if (!s.empty()) {
                    s.pop_back();
                }
            }
            else {
                s.push_back(t);
            }

            i = j + 1;
        }

        string r;
        for (const auto& t : s) {
            r += "/" + t;
        }
        if (r.empty()) {
            r += "/";
        }
        return r;
    }
};
