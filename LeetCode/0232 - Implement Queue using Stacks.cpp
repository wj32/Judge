class MyQueue {
private:
    stack<int> r;
    stack<int> s;

    void transfer() {
        while (!r.empty()) {
            s.push(r.top());
            r.pop();
        }
    }

public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        r.push(x);
        if (s.empty()) {
            transfer();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        const auto x = s.top();
        s.pop();
        if (s.empty()) {
            transfer();
        }
        return x;
    }

    /** Get the front element. */
    int peek() {
        return s.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
