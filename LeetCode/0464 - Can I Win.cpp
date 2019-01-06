class Solution {
public:
    bool recurse(unordered_map<int, bool>* cache, int m, int s, int n) {
        const auto it = cache->find(s);
        if (it != cache->end()) {
            return it->second;
        }
        const auto r = [&] {
            const int minimum = [&] {
                for (int x = 1; x <= m; x++) {
                    if ((s & (1 << (x - 1))) != 0) {
                        return x;
                    }
                }
                return -1;
            }();
            const int maximum = [&] {
                for (int x = m; x >= 1; x--) {
                    if ((s & (1 << (x - 1))) != 0) {
                        return x;
                    }
                }
                return -1;
            }();
            if (n <= maximum) {
                return true;
            }
            if ((n > maximum) && (n <= maximum + minimum)) {
                return false;
            }
            for (int x = 1; x <= m; x++) {
                const int mask = 1 << (x - 1);
                if ((s & mask) != 0) {
                    if (!recurse(cache, m, s & ~mask, n - x)) {
                        return true;
                    }
                }
            }
            return false;
        }();
        cache->insert({s, r});
        return r;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        const int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if (desiredTotal == sum) {
            return (maxChoosableInteger % 2) != 0;
        }
        if (desiredTotal > sum) {
            return false;
        }
        if (desiredTotal <= maxChoosableInteger) {
            return true;
        }
        if (desiredTotal == maxChoosableInteger + 1) {
            return false;
        }
        if (desiredTotal <= maxChoosableInteger * 2) {
            return true;
        }
        unordered_map<int, bool> cache;
        return recurse(&cache, maxChoosableInteger, (1 << maxChoosableInteger) - 1, desiredTotal);
    }
};
