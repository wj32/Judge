class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());
        int result = 0;
        int t = 0;
        auto it = clips.begin();
        while (t < time && it != clips.end()) {
            int next = t;
            while (it != clips.end() && (*it)[0] <= t) {
                next = max(next, (*it)[1]);
                ++it;
            }
            if (next == t) {
                break;
            }
            ++result;
            t = next;
        }
        return t >= time ? result : -1;
    }
};