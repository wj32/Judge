class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> seen(rooms.size(), false);
        int seenCount = 0;
        vector<int> u;
        vector<int> v;

        seen[0] = true;
        u.push_back(0);
        seenCount++;
        if (seenCount == rooms.size()) {
            return true;
        }

        while (!u.empty()) {
            for (const auto room : u) {
                for (const auto connectedRoom : rooms[room]) {
                    if (!seen[connectedRoom]) {
                        seen[connectedRoom] = true;
                        v.push_back(connectedRoom);
                        seenCount++;
                        if (seenCount == rooms.size()) {
                            return true;
                        }
                    }
                }
            }

            u.clear();
            swap(u, v);
        }

        return false;
    }
};
