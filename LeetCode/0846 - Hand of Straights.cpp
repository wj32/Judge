class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if (W == 1) {
            return true;
        }
        if ((hand.size() % W) != 0) {
            return false;
        }

        sort(hand.begin(), hand.end());

        deque<int> q;
        int i = 0;

        while (i < hand.size()) {
            const int x = hand[i];
            int j = i + 1;
            while ((j < hand.size()) && (hand[j] == x)) {
                j++;
            }

            if ((i != 0) && (hand[i - 1] + 1 != x) && !q.empty()) {
                return false;
            }

            int count = j - i;

            if (count < q.size()) {
                return false;
            }

            count -= q.size();

            while (!q.empty() && (q.front() == x - W + 1)) {
                q.pop_front();
            }

            q.insert(q.end(), count, x);

            i = j;
        }

        return q.empty();
    }
};
