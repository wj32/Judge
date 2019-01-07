class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int distance = 0;
        int i = 0;
        for (const int house : houses) {
            while ((i < heaters.size()) && (heaters[i] <= house)) {
                i++;
            }
            int minDistance = numeric_limits<int>::max();
            if (i > 0) {
                minDistance = min(minDistance, abs(house - heaters[i - 1]));
            }
            if (i < heaters.size()) {
                minDistance = min(minDistance, abs(house - heaters[i]));
            }
            distance = max(distance, minDistance);
        }
        return distance;
    }
};
