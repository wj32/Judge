class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) {
            return false;
        }

        array<int, 26> counts{};
        for (const char c : s1) {
            counts[c - 'a']++;
        }

        array<int, 26> balances = counts;
        for (int i = 0; i < s1.size(); i++) {
            balances[s2[i] - 'a']--;
        }

        int balance = 0;
        for (int i = 0; i < 26; i++) {
            if (balances[i] != 0) {
                balance++;
            }
        }

        if (balance == 0) {
            return true;
        }

        for (int i = s1.size(); i < s2.size(); i++) {
            auto& inc = balances[s2[i - s1.size()] - 'a'];
            inc++;
            if (inc == 0) {
                balance--;
            }
            else if (inc == 1) {
                balance++;
            }

            auto& dec = balances[s2[i] - 'a'];
            dec--;
            if (dec == 0) {
                balance--;
            }
            else if (dec == -1) {
                balance++;
            }

            if (balance == 0) {
                return true;
            }
        }

        return false;
    }
};
