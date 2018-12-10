class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        const string b = "ACGT";
        array<int, 26> br{};
        for (int i = 0; i < b.size(); i++) {
            br[b[i] - 'A'] = i;
        }
        const auto encode = [&](const string& s) {
            int value = 0;
            for (int i = 0; i < 8; i++) {
                value |= br[s[i] - 'A'] << (i * 2);
            }
            return value;
        };

        vector<bool> v(1 << (8 * 2), false);
        for (const auto& s : bank) {
            v[encode(s)] = true;
        }

        const int encodedStart = encode(start);
        const int encodedEnd = encode(end);
        vector<int> p;
        vector<int> q;
        int distance = 0;
        v[encodedStart] = false;
        p.push_back(encodedStart);
        while (!p.empty()) {
            for (const auto& s : p) {
                if (s == encodedEnd) {
                    return distance;
                }
                for (int i = 0; i < 8; i++) {
                    const int mask = 3 << (i * 2);
                    const int original = s & mask;
                    const int sb = s & ~mask;
                    for (int j = 0; j < 4; j++) {
                        const int modified = j << (i * 2);
                        if (modified != original) {
                            const int sn = sb | modified;
                            if (v[sn]) {
                                v[sn] = false;
                                q.push_back(sn);
                            }
                        }
                    }
                }
            }
            swap(p, q);
            q.clear();
            distance++;
        }
        return -1;
    }
};
