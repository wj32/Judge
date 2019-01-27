class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        const int z = stoi(target);
        vector<bool> seen(10000, false);
        vector<int> u;
        vector<int> v;
        int distance = 0;

        for (const auto& deadend : deadends) {
            seen[stoi(deadend)] = true;
        }

        const auto enqueue = [&](int x) {
            if (!seen[x]) {
                seen[x] = true;
                v.push_back(x);
            }
        };

        if (seen[0]) {
            return -1;
        }
        u.push_back(0);

        while (!u.empty()) {
            for (const auto x : u) {
                if (x == z) {
                    return distance;
                }

                int position = 1;
                for (int i = 0; i < 4; i++) {
                    const int digit = (x / position) % 10;
                    enqueue((digit == 0) ? (x + (9 * position)) : (x - position));
                    enqueue((digit == 9) ? (x - (9 * position)) : (x + position));
                    position *= 10;
                }
            }

            u.clear();
            swap(u, v);
            distance++;
        }

        return -1;
    }
};
