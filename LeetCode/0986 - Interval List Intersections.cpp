class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        auto first = firstList.begin();
        auto second = secondList.begin();
        vector<vector<int>> resultList;
        while (first != firstList.end() && second != secondList.end()) {
            const auto a = max((*first)[0], (*second)[0]);
            const auto b = min((*first)[1], (*second)[1]);
            if (a <= b) {
                resultList.push_back(vector{a, b});
            }
            const auto advance = [&](auto& it) {
                if ((*it)[1] <= b) {
                    ++it;
                } else {
                    (*it)[0] = max((*it)[0], b + 1);
                }
            };
            advance(first);
            advance(second);
        }
        return resultList;
    }
};