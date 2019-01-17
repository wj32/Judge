class Solution {
public:
    int parseTime(const string& time) {
        return (60 * (((time[0] - '0') * 10) + (time[1] - '0'))) + (((time[3] - '0') * 10) + (time[4] - '0'));
    }

    int diffTime(int time1, int time2) {
        const int day = 24 * 60;
        int diff = abs(time1 - time2) % day;
        if (diff > day / 2) {
            return day - diff;
        }
        else {
            return diff;
        }
    }

    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int minimum = numeric_limits<int>::max();
        int prevTime = parseTime(timePoints.back());
        for (const auto& timeString : timePoints) {
            const int time = parseTime(timeString);
            minimum = min(minimum, diffTime(prevTime, time));
            prevTime = time;
        }
        return minimum;
    }
};
