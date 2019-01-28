class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> m;
        for (const int x : answers) {
            m[x]++;
        }

        int rabbits = 0;
        for (const auto& p : m) {
            rabbits += (p.second + p.first) / (p.first + 1) * (p.first + 1); // Round up to multiple of p.first + 1
        }
        return rabbits;
    }
};
