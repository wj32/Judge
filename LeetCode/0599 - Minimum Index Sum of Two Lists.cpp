class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        if (list1.size() > list2.size()) {
            swap(list1, list2);
        }
        unordered_map<string, int> m;
        for (int i = 0; i < list1.size(); i++) {
            m[list1[i]] = -i;
        }

        int minimum = numeric_limits<int>::max();

        for (int i = 0; i < list2.size(); i++) {
            const auto it = m.find(list2[i]);
            if (it != m.end()) {
                it->second = -it->second + i;
                minimum = min(minimum, it->second);
            }
        }

        vector<string> v;
        for (const auto& p : m) {
            if (p.second == minimum) {
                v.push_back(p.first);
            }
        }
        return v;
    }
};
