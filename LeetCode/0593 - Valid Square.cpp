class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<pair<int, int>> v = {{p1[0], p1[1]}, {p2[0], p2[1]}, {p3[0], p3[1]}, {p4[0], p4[1]}};
        vector<int> lengths;
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                const auto a = v[i].first - v[j].first;
                const auto b = v[i].second - v[j].second;
                lengths.push_back((a * a) + (b * b));
            }
        }
        sort(lengths.begin(), lengths.end());
        return
            (lengths[0] != 0) &&
            (lengths[0] == lengths[1]) &&
            (lengths[1] == lengths[2]) &&
            (lengths[2] == lengths[3]) &&
            (lengths[3] * 2 == lengths[4]) &&
            (lengths[4] == lengths[5]);
    }
};
