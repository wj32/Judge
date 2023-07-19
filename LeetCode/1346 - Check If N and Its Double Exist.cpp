class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        for (const auto x : arr) {
            if (s.find(x * 2) != s.end() || (x % 2 == 0 && s.find(x / 2) != s.end())) {
                return true;
            }
            s.insert(x);
        }
        return false;
    }
};