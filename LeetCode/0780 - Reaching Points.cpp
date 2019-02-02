class Solution {
public:
    bool recurse(int sx, int sy, int tx, int ty) {
        if (tx < sx) {
            return false;
        }
        else if (tx == sx) {
            return ((ty - sy) % sx) == 0;
        }
        else {
            return recurse(sy, sx, ty % tx, tx);
        }
    }

    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if (tx < ty) {
            return recurse(sx, sy, tx, ty);
        }
        else {
            return recurse(sy, sx, ty, tx);
        }
    }
};
