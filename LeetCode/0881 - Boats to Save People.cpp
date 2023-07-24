class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boats = 0;
        sort(people.begin(), people.end());
        int left = 0;
        int right = people.size() - 1;
        for (; right > left; --right) {
            if (people[right] + people[left] <= limit) {
                ++left;
            }
            ++boats;
        }
        return boats + (left <= right ? 1 : 0);
    }
};