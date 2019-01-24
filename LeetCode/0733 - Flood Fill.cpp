class Solution {
public:
    void search(vector<vector<int>>& m, int i, int j, int oldColor, int newColor) {
        if (m[i][j] != oldColor) {
            return;
        }
        m[i][j] = newColor;

        if (i > 0) {
            search(m, i - 1, j, oldColor, newColor);
        }
        if (i < m.size() - 1) {
            search(m, i + 1, j, oldColor, newColor);
        }
        if (j > 0) {
            search(m, i, j - 1, oldColor, newColor);
        }
        if (j < m[0].size() - 1) {
            search(m, i, j + 1, oldColor, newColor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] != newColor) {
            search(image, sr, sc, image[sr][sc], newColor);
        }
        return image;
    }
};
