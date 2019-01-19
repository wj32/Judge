class MyCircularQueue {
private:
    vector<int> values;
    size_t count = 0;
    size_t front = 0;

    inline size_t modLimited(size_t k, size_t n) {
        if (k < n) {
            return k;
        }
        else {
            return k - n;
        }
    }

public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        values.resize(k);
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (count == values.size()) {
            return false;
        }
        values[modLimited(front + count, values.size())] = value;
        count++;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front = modLimited(front + 1, values.size());
        count--;
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return values[front];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return values[modLimited(front + count - 1, values.size())];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return count == 0;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return count == values.size();
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
