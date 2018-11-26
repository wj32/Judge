class Solution {
public:
    struct State {
        int lh;
        int tw;
        int rh;
        int bw;
    };

    bool isSelfCrossing(vector<int>& x) {
        //               tw                                    tw
        // .    *-----------------*              .    *-----------------*
        // .    |                 | rh           .    |                 |
        // .    |                 |              .    |                 |
        // 5    |        cx *-----* ry           5    |                 |
        // 4 lh |              bw         OR     4 lh |                 | rh
        // 3    |                                3    |                 |
        // 2    |                                2    |                 |
        // 1    *----->* nx                      1    *----->* nx       |
        //    (1,1)                                 (1,1)               * ry
        //                                                                bw=1
        //      12345...                              12345...
        //
        // All lengths are inclusive of the endpoints.

        if (x.size() < 3) {
            return false;
        }

        State s = {x[2] + 1, x[1] + 1, x[0] + 1, 1};

        for (size_t i = 3; i < x.size(); i++) {
            const int nx = 1 + x[i];
            const int cx = s.tw - s.bw + 1;
            const int ry = s.lh - s.rh + 1;

            if ((nx >= s.tw) && (ry <= 1)) {
                return true;
            }

            // Rotate clockwise.
            State t;
            t.lh = nx;
            if (nx <= s.tw) {
                if (nx < cx) {
                    t.tw = s.lh;
                }
                else {
                    t.tw = ry;
                }
                t.rh = nx;
                t.bw = 1;
            }
            else {
                t.tw = s.lh;
                t.rh = s.tw;
                t.bw = s.rh;
            }
            s = t;

            // cout << "lh = " << s.lh << "; tw = " << s.tw << "; rh = " << s.rh << "; bw = " << s.bw << endl;
        }

        return false;
    }
};
