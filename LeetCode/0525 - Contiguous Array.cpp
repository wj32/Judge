class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLength = 0;
        int balance = 0;
        unordered_map<int, int> s;
        s.insert({0, 0});
        for (int i = 0; i < nums.size(); i++) {
            balance += ((nums[i] == 1) ? 1 : -1);
            const auto it = s.find(balance);
            if (it != s.end()) {
                maxLength = max(maxLength, i + 1 - it->second);
            }
            else {
                s.insert({balance, i + 1});
            }
        }
        return maxLength;
    }
};
