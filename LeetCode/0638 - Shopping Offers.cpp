class Solution {
public:
    int get3(int x, int index) {
        return (x >> (index * 3)) & 0x7;
    }

    int set3(int x, int index, int value) {
        x &= ~(0x7 << (index * 3));
        x |= value << (index * 3);
        return x;
    }

    int recurse(const vector<int>& prices, const vector<vector<int>>& special, int specialIndex, int remaining, unordered_map<int, int>& cache) {
        if (remaining == 0) {
            return 0;
        }
        const auto key = remaining | (specialIndex << 24);
        const auto it = cache.find(key);
        if (it != cache.end()) {
            return it->second;
        }
        const auto result = [&] {
            if (specialIndex == special.size()) {
                int totalPrice = 0;
                for (int i = 0; i < prices.size(); i++) {
                    totalPrice += get3(remaining, i) * prices[i];
                }
                return totalPrice;
            }

            int minimum = recurse(prices, special, specialIndex + 1, remaining, cache);

            bool specialOk = true;
            int newRemaining = remaining;
            for (int i = 0; i < prices.size(); i++) {
                const int quantity = get3(newRemaining, i);
                if (quantity < special[specialIndex][i]) {
                    specialOk = false;
                    break;
                }
                newRemaining = set3(newRemaining, i, quantity - special[specialIndex][i]);
            }

            if (specialOk) {
                minimum = min(minimum,
                              special[specialIndex][prices.size()] +
                                  recurse(prices, special, specialIndex, newRemaining, cache));
            }

            return minimum;
        }();
        cache.insert({key, result});
        return result;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        unordered_map<int, int> cache;
        int remaining = 0;
        for (int i = 0; i < needs.size(); i++) {
            remaining = set3(remaining, i, needs[i]);
        }
        return recurse(price, special, 0, remaining, cache);
    }
};
