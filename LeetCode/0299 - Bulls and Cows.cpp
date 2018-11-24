class Solution {
public:
    string getHint(string secret, string guess) {
        array<pair<int, int>, 10> c = {};
        int bulls = 0;
        for (size_t i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            }
            else {
                c[secret[i] - '0'].first++;
                c[guess[i] - '0'].second++;
            }
        }
        int cows = 0;
        for (const auto& p : c) {
            cows += min(p.first, p.second);
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
