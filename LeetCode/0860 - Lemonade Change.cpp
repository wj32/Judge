class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        for (const auto bill : bills) {
            switch (bill) {
                case 5:
                    five++;
                    break;
                case 10:
                    if (five == 0) {
                        return false;
                    }
                    ten++;
                    five--;
                    break;
                case 20:
                    if (ten != 0) {
                        if (five == 0) {
                            return false;
                        }
                        ten--;
                        five--;
                    }
                    else {
                        if (five < 3) {
                            return false;
                        }
                        five -= 3;
                    }
                    break;
                default:
                    assert(false);
                    break;
            }
        }
        return true;
    }
};
