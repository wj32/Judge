class Solution {
public:
    string reorganizeString(string S) {
        array<int, 26> a{};
        for (const char c : S) {
            a[c - 'a']++;
        }

        priority_queue<pair<int, char>> q;
        for (int i = 0; i < 26; i++) {
            if (a[i] != 0) {
                q.push({a[i], 'a' + i});
            }
        }

        string r;
        pair<int, char> pending = {0, ' '};

        while (!q.empty()) {
            auto entry = q.top();
            q.pop();

            entry.first--;
            r.append(1, entry.second);

            if (pending.first != 0) {
                q.push(pending);
                pending = {0, ' '};
            }

            if (entry.first != 0) {
                pending = entry;
            }
        }

        if (pending.first != 0) {
            return "";
        }

        return r;
    }
};
