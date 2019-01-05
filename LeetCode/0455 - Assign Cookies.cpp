class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int j = 0;
        int satisfied = 0;
        for (const int x : g) {
            while ((j < s.size()) && (s[j] < x)) {
                j++;
            }
            if (j == s.size()) {
                break;
            }
            satisfied++;
            j++;
        }
        return satisfied;
    }
};
