/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode* copyRandomList(RandomListNode* head) {
        RandomListNode clonedBase(0);
        auto clonedTail = &clonedBase;
        unordered_map<RandomListNode*, RandomListNode*> clonedNodes;

        while (head != nullptr) {
            const auto clonedNode = new RandomListNode(head->label);
            clonedTail->next = clonedNode;
            clonedTail = clonedNode;
            clonedNodes.insert({head, clonedNode});
            head = head->next;
        }

        for (const auto& p : clonedNodes) {
            if (p.first->random != nullptr) {
                p.second->random = clonedNodes.find(p.first->random)->second;
            }
        }

        return clonedBase.next;
    }
};
