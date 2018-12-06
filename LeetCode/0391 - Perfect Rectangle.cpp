class Solution {
public:
    struct Point {
        int x;
        int y;
    };

    bool isRectangleCover(vector<vector<int>>& rectangles) {
        if (rectangles.empty()) {
            return false;
        }

        unordered_set<long long> points;
        const auto toggle = [&](const Point& p) {
            const auto value = p.x | (static_cast<long long>(p.y) << 32);
            const auto it = points.find(value);
            if (it != points.end()) {
                points.erase(it);
            }
            else {
                points.insert(value);
            }
        };

        int minLeft = numeric_limits<int>::max();
        int maxRight = numeric_limits<int>::min();
        int minBottom = numeric_limits<int>::max();
        int maxTop = numeric_limits<int>::min();

        long long smallArea = 0;

        for (const auto& rectangle : rectangles) {
            const Point bl{rectangle[0], rectangle[1]};
            const Point tr{rectangle[2], rectangle[3]};
            const Point br{tr.x, bl.y};
            const Point tl{bl.x, tr.y};

            toggle(bl);
            toggle(tr);
            toggle(br);
            toggle(tl);

            minLeft = min(minLeft, bl.x);
            maxRight = max(maxRight, tr.x);
            minBottom = min(minBottom, bl.y);
            maxTop = max(maxTop, tr.y);

            smallArea += static_cast<long long>(tr.x - bl.x) * (tr.y - bl.y);
        }

        const auto largeArea = static_cast<long long>((maxRight - minLeft) * (maxTop - minBottom));

        if (smallArea != largeArea) {
            return false;
        }

        toggle({minLeft, minBottom});
        toggle({maxRight, minBottom});
        toggle({maxRight, maxTop});
        toggle({minLeft, maxTop});

        return points.empty();
    }
};
