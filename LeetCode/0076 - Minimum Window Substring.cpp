class Solution {
public:
    string minWindow(string s, string t) {
        if ((s.size() == 0) || (t.size() == 0)) {
            return "";
        }

        map<char, int> g;
        for (char c : t) {
            const auto it = g.find(c);
            if (it == g.end()) {
                g.insert({c, 1});
            }
            else {
                it->second++;
            }
        }

        map<char, int> h;
        int ok = 0;
        for (const auto& p : g) {
            h.insert({p.first, 0});
        }

        int start = 0;
        int end = 0;
        pair<int, int> minWindow = {-1, s.size() + 1};

        while (end < s.size()) {
            {
                const auto it = h.find(s[end]);
                if (it != h.end()) {
                    if (++it->second == g[s[end]]) {
                        ok++;
                    }
                }
                end++;
            }

            while (ok >= g.size()) {
                if (minWindow.second > end - start) {
                    minWindow = {start, end - start};
                }

                const auto it2 = h.find(s[start]);
                if (it2 != h.end()) {
                    if (--it2->second == g[s[start]] - 1) {
                        ok--;
                    }
                }
                start++;
            }
        }

        if (minWindow.first != -1) {
            return s.substr(minWindow.first, minWindow.second);
        }
        else {
            return "";
        }
    }
};
