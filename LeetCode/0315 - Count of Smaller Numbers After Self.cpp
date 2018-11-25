class Solution {
public:
    void recurse(vector<int>& m, vector<int>& a, vector<int>& c, vector<int>& t, int start, int count) {
        // cout << "entry [" << start << ", " << count << "]" << endl;
        if (count == 0) {
            return;
        }
        if (count == 1) {
            c[start] = 0;
            return;
        }

        const int leftCount = count / 2;
        recurse(m, a, c, t, start, leftCount);
        const int rightStart = start + leftCount;
        const int rightCount = count - leftCount;
        recurse(m, a, c, t, rightStart, rightCount);

        int leftIndex = start + leftCount - 1;
        int rightIndex = rightStart + rightCount - 1;
        int rightOutputCount = 0;
        int tempIndex = count - 1;

        // cout << "merging [" << start << ", " << count << "]" << endl;
        while ((leftIndex >= start) && (rightIndex >= rightStart)) {
            if (a[m[leftIndex]] <= a[m[rightIndex]]) {
                c[m[leftIndex]] += rightOutputCount;
                t[tempIndex] = m[leftIndex];
                leftIndex--;
            }
            else {
                rightOutputCount++;
                t[tempIndex] = m[rightIndex];
                rightIndex--;
            }
            tempIndex--;
        }

        while (leftIndex >= start) {
            c[m[leftIndex]] += rightOutputCount;
            t[tempIndex] = m[leftIndex];
            leftIndex--;
            tempIndex--;
        }

        while (rightIndex >= rightStart) {
            t[tempIndex] = m[rightIndex];
            rightIndex--;
            tempIndex--;
        }

        copy(t.begin(), t.begin() + count, m.begin() + start);

        // for (const int i : m) {
        //     cout << a[i] << " ";
        // }
        // cout << endl;
        // for (const int i : m) {
        //     cout << c[i] << " ";
        // }
        // cout << endl;
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<int> indices(nums.size());
        for (size_t i = 0; i < nums.size(); i++) {
            indices[i] = i;
        }
        vector<int> counts(nums.size());
        vector<int> temp(nums.size());
        recurse(indices, nums, counts, temp, 0, nums.size());
        return counts;
    }
};
