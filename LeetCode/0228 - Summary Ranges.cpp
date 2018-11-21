class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0) {
            return {};
        }

        vector<string> r;
        int x = nums[0];
        int y = x;

        const auto record = [&]() {
            if (x != y) {
                r.push_back(to_string(x) + "->" + to_string(y));
            }
            else {
                r.push_back(to_string(x));
            }
        };

        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] == y + 1) {
                y++;
            }
            else {
                record();
                x = nums[i];
                y = x;
            }
        }

        record();

        return r;
    }
};
