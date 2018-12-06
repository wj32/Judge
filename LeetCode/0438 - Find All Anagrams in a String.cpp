class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) {
            return {};
        }

        array<int, 26> counts{};
        for (size_t i = 0; i < p.size(); i++) {
            counts[p[i] - 'a']++;
            counts[s[i] - 'a']--;
        }

        int nonZeroCount = 26;
        for (const int count : counts) {
            if (count == 0) {
                nonZeroCount--;
            }
        }

        vector<int> r;

        if (nonZeroCount == 0) {
            r.push_back(0);
        }

        const auto limit = s.size() - p.size();
        for (size_t i = 0; i < limit; i++) {
            const auto updateNonZeroCount = [&](int oldCount) {
                if (oldCount == -1) {
                    nonZeroCount--;
                }
                else if (oldCount == 0) {
                    nonZeroCount++;
                }
            };

            updateNonZeroCount(counts[s[i] - 'a']++);
            updateNonZeroCount(-(counts[s[i + p.size()] - 'a']--));

            if (nonZeroCount == 0) {
                r.push_back(i + 1);
            }
        }

        return r;
    }
};
