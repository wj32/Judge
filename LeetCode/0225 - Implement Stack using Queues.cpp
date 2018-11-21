class MyStack {
private:
    queue<int> q;

public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        queue<int> q2;

        q2.push(x);

        while (!q.empty()) {
            q2.push(q.front());
            q.pop();
        }

        q = q2;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        const auto x = q.front();
        q.pop();
        return x;
    }

    /** Get the top element. */
    int top() {
        return q.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
