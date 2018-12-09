/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* recurse(Node* head) {
        Node* last;
        while (head != nullptr) {
            last = head;
            const auto next = head->next;
            if (head->child != nullptr) {
                last = recurse(head->child);
                last->next = next;
                if (next != nullptr) {
                    next->prev = last;
                }
                head->next = head->child;
                head->child->prev = head;
                head->child = nullptr;
            }
            head = next;
        }
        return last;
    }

    Node* flatten(Node* head) {
        recurse(head);
        return head;
    }
};
