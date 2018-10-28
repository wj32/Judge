class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 0) {
            return {};
        }

        vector<vector<int>> m(n);

        for (int i = 0; i < n; i++) {
            m[i].resize(n);
        }

        int x = 1;
        int left = 0;
        int top = 0;
        int right = n - 1;
        int bottom = n - 1;

        while ((left <= right) && (top <= bottom)) {
            for (int j = left; j <= right; j++) {
                m[top][j] = x++;
            }
            top++;
            if (top > bottom) {
                break;
            }

            for (int i = top; i <= bottom; i++) {
                m[i][right] = x++;
            }
            right--;
            if (right < left) {
                break;
            }

            for (int j = right; j >= left; j--) {
                m[bottom][j] = x++;
            }
            bottom--;
            if (bottom < top) {
                break;
            }

            for (int i = bottom; i >= top; i--) {
                m[i][left] = x++;
            }
            left++;
            if (left > right) {
                break;
            }
        }

        return m;
    }
};
