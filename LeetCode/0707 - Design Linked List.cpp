class MyLinkedList {
    struct Node {
        Node* prev;
        Node* next;
        int val;
    };

    Node head;

    Node* addAfter(Node* position, int val) {
        const auto node = new Node{position, position->next, val};
        position->next->prev = node;
        position->next = node;
        return node;
    }

    Node* addBefore(Node* position, int val) {
        const auto node = new Node{position->prev, position, val};
        position->prev->next = node;
        position->prev = node;
        return node;
    }

    void remove(Node* node) {
        const auto prev = node->prev;
        const auto next = node->next;
        node->prev->next = next;
        node->next->prev = prev;
        delete node;
    }

    pair<Node*, int> at(int index) {
        Node* node = &head;
        index++;
        while (index > 0) {
            index--;
            node = node->next;
            if (node == &head) {
                break;
            }
        }
        return {node, index};
    }

public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = {&head, &head, -1};
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        return at(index).first->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        addAfter(&head, val);
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        addBefore(&head, val);
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        const auto [node, excess] = at(index);
        if (excess == 0) {
            addBefore(node, val);
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        const auto node = at(index).first;
        if (node != &head) {
            remove(node);
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
