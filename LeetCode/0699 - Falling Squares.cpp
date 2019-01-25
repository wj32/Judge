class Solution {
public:
    vector<int> fallingSquares(vector<pair<int, int>>& positions) {
        struct Entry {
            int right;
            int height;
        };
        map<int, Entry> m;
        vector<int> maxHeights;
        int maxHeight = 0;

        for (const auto& square : positions) {
            const auto squareLeft = square.first;
            const auto squareRight = squareLeft + square.second - 1;
            const auto squareHeight = square.second;

            auto it = m.upper_bound(squareRight);
            int oldHeight = 0;
            while (it != m.begin()) {
                auto itp = prev(it);
                assert(itp->first <= squareRight);
                if (itp->second.right < squareLeft) {
                    break;
                }
                oldHeight = max(oldHeight, itp->second.height);
                if (itp->first >= squareLeft) {
                    if (itp->second.right > squareRight) {
                        const pair<int, Entry> element{squareRight + 1, {itp->second.right, itp->second.height}};
                        itp = m.erase(itp);
                        itp = m.insert(itp, element);
                    }
                    else {
                        itp = m.erase(itp);
                    }
                }
                else {
                    if (itp->second.right > squareRight) {
                        it = m.insert(it, {squareRight + 1, {itp->second.right, itp->second.height}});
                    }
                    itp->second.right = squareLeft - 1;
                    break;
                }
                it = itp;
            }

            const int newHeight = oldHeight + squareHeight;
            m.insert(it, {squareLeft, {squareRight, newHeight}});

            maxHeight = max(maxHeight, newHeight);
            maxHeights.push_back(maxHeight);

            // for (const auto& p : m) {
            //     cout << "[" << p.first << ", " << p.second.right << "]: " << p.second.height << "   ";
            // }
            // cout << endl;
        }

        return maxHeights;
    }
};
