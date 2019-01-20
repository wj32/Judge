class Solution {
public:
    string predictPartyVictory(string senate) {
        array<int, 2> pendingKills{};
        array<int, 2> remaining{};
        for (const char c : senate) {
            remaining[(c == 'R') ? 1 : 0]++;
        }
        if ((remaining[0] != 0) && (remaining[1] != 0)) {
            int index = 0;
            while (true) {
                if (senate[index] != ' ') {
                    const int type = (senate[index] == 'R') ? 1 : 0;
                    if (pendingKills[type] != 0) {
                        senate[index] = ' ';
                        pendingKills[type]--;
                        remaining[type]--;
                        if (remaining[type] == 0) {
                            break;
                        }
                    }
                    else {
                        pendingKills[1 - type]++;
                    }
                }
                index++;
                if (index == senate.size()) {
                    index = 0;
                }
            }
        }
        return (remaining[0] != 0) ? "Dire" : "Radiant";
    }
};
