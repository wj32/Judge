class Solution {
public:
    void search(int k, string node, unordered_set<string>& seen, string& tour) {
        auto edge = node;
        for (int i = 0; i < k; i++) {
            edge.append(1, '0' + i);
            if (seen.find(edge) == seen.end()) {
                seen.insert(edge);
                search(k, edge.substr(1), seen, tour);
                tour.append(1, '0' + i);
            }
            edge.erase(edge.size() - 1, 1);
        }
    }

    string crackSafe(int n, int k) {
        unordered_set<string> seen;
        string tour;
        search(k, string(n - 1, '0'), seen, tour);
        tour.append(n - 1, '0');
        return tour;
    }
};
