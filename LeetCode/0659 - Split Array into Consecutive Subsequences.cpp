class Solution {
public:
    bool isPossible(vector<int>& nums) {
        if (nums.empty()) {
            return true;
        }

        int bias = 0;
        deque<int> q;
        int i = 1;
        while ((i < nums.size()) && (nums[i] == nums[0])) {
            i++;
        }
        q.insert(q.end(), i, 1);

        while (i < nums.size()) {
            const int previous = nums[i - 1];
            const int current = nums[i];

            int j = i + 1;
            while ((j < nums.size()) && (nums[j] == current)) {
                j++;
            }
            int count = j - i;
            auto keep = q.end();

            if (current == previous + 1) {
                const int keepCount = min(count, static_cast<int>(q.size()));
                count -= keepCount;
                keep -= keepCount;
            }

            if ((keep != q.begin()) && (*prev(keep) + bias < 3)) {
                return false;
            }

            bias++;
            q.erase(q.begin(), keep);
            q.insert(q.end(), count, -bias + 1);

            i = j;
        }

        if (!q.empty() && (q.back() + bias < 3)) {
            return false;
        }

        return true;
    }
};
