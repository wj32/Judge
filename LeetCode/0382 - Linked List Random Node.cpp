/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* head;

    random_device rd;
    mt19937 gen;

public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* h) : gen(rd()) {
        head = h;
    }

    /** Returns a random node's value. */
    int getRandom() {
        int n = 0;
        ListNode* node = nullptr;
        auto current = head;
        while (current != nullptr) {
            n++;
            std::uniform_int_distribution<> dist(1, n);
            if (dist(gen) == 1) {
                node = current;
            }
            current = current->next;
        }
        return node->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
