class Solution {
public:
    vector<int> constructRectangle(int area) {
        for (int i = static_cast<int>(sqrt(area)); i >= 1; i--) {
            if ((area % i) == 0) {
                return {area / i, i};
            }
        }
        return {};
    }
};
