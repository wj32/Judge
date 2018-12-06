/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* const trueNode = new Node(true, true, nullptr, nullptr, nullptr, nullptr);
    Node* const falseNode = new Node(false, true, nullptr, nullptr, nullptr, nullptr);

    Node* recurse(const vector<vector<int>>& grid, int i, int j, int width) {
        if (width == 1) {
            return (grid[i][j] != 0) ? trueNode : falseNode;
        }

        const auto halfWidth = width / 2;
        const auto tl = recurse(grid, i, j, halfWidth);
        const auto tr = recurse(grid, i, j + halfWidth, halfWidth);
        const auto bl = recurse(grid, i + halfWidth, j, halfWidth);
        const auto br = recurse(grid, i + halfWidth, j + halfWidth, halfWidth);

        if ((tl == tr) && (tr == bl) && (bl == br)) {
            return tl;
        }
        else {
            return new Node(false, false, tl, tr, bl, br);
        }
    }

    Node* construct(vector<vector<int>>& grid) {
        if (grid.size() == 0) {
            return nullptr;
        }
        return recurse(grid, 0, 0, grid.size());
    }
};
