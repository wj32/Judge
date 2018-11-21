class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        const long long left = max(A, E);
        const long long right = min(C, G);
        const auto width = max(right - left, 0ll);

        const long long bottom = max(B, F);
        const long long top = min(D, H);
        const auto height = max(top - bottom, 0ll);

        const auto area1 = static_cast<long long>(C - A) * (D - B);
        const auto area2 = static_cast<long long>(G - E) * (H - F);
        const auto area3 = width * height;

        return static_cast<int>(area1 + area2 - area3);
    }
};
