/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    bool colinear(const Point& p1, const Point& p2, const Point& p3) {
        return
            (p1.x * (static_cast<long long>(p2.y) - p3.y)) +
            (p2.x * (static_cast<long long>(p3.y) - p1.y)) +
            (p3.x * (static_cast<long long>(p1.y) - p2.y)) == 0;
    }

    struct Line {
        Point r1;
        Point r2;
        int count;
    };

    int maxPoints(vector<Point>& points) {
        const auto comparePoint = [&](const Point& p1, const Point& p2) {
            if (p1.x != p2.x) {
                return p1.x < p2.x;
            }
            else {
                return p1.y < p2.y;
            }
        };
        map<Point, int, decltype(comparePoint)> counts(comparePoint);
        for (const auto& p : points) {
            const auto it = counts.find(p);
            if (it != counts.end()) {
                it->second++;
            }
            else {
                counts.insert({p, 1});
            }
        }

        vector<Line*> lines;

        int maxCount = 0;

        for (auto it1 = counts.begin(); it1 != counts.end(); it1++) {
            maxCount = max(maxCount, it1->second);

            const auto& p1 = it1->first;
            auto it2 = it1;
            it2++;
            for (; it2 != counts.end(); it2++) {
                maxCount = max(maxCount, it1->second + it2->second);

                const auto& p2 = it2->first;
                Line* line = nullptr;
                auto it3 = it2;
                it3++;
                for (; it3 != counts.end(); it3++) {
                    const auto& p3 = it3->first;
                    if (colinear(p1, p2, p3)) {
                        // cout << "colinear: (" << p1.x << ", " << p1.y << ") # (" << p2.x << ", " << p2.y << ") # (" << p3.x << ", " << p3.y << ")" << endl;
                        if (line == nullptr) {
                            for (const auto existingLine : lines) {
                                if (colinear(existingLine->r1, existingLine->r2, p1) &&
                                    colinear(existingLine->r1, existingLine->r2, p2)) {
                                    line = existingLine;
                                    break;
                                }
                            }
                            if (line != nullptr) {
                                // cout << "skipping: (" << p1.x << ", " << p1.y << ") # (" << p2.x << ", " << p2.y << ") on (" << line->r1.x << ", " << line->r1.y << ") # (" << line->r2.x << ", " << line->r2.y << ")" << endl;
                                break;
                            }
                            line = new Line{p1, p2, it1->second + it2->second};
                            lines.push_back(line);
                        }
                        // cout << "adding: (" << p3.x << ", " << p3.y << ") to (" << line->r1.x << ", " << line->r1.y << ") # (" << line->r2.x << ", " << line->r2.y << ")" << endl;
                        line->count += it3->second;
                    }
                    else {
                        // cout << "NOT colinear: (" << p1.x << ", " << p1.y << ") ; (" << p2.x << ", " << p2.y << ") ; (" << p3.x << ", " << p3.y << ")" << endl;
                    }
                }
            }
        }

        for (const auto line : lines) {
            maxCount = max(maxCount, line->count);
        }

        return maxCount;
    }
};
