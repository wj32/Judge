/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
private:
    stack<tuple<const vector<NestedInteger>*, const NestedInteger*, size_t>> s;

    void normalize() {
        while (!s.empty() && (get<0>(s.top()) != nullptr)) {
            if (get<2>(s.top()) < get<0>(s.top())->size()) {
                const auto& element = (*get<0>(s.top()))[get<2>(s.top())];
                get<2>(s.top())++;
                if (element.isInteger()) {
                    s.push({nullptr, &element, 0});
                }
                else {
                    s.push({&element.getList(), nullptr, 0});
                }
            }
            else {
                s.pop();
            }
        }
    }

public:
    NestedIterator(vector<NestedInteger>& nestedList) {
        s.push({&nestedList, nullptr, 0});
        normalize();
    }

    int next() {
        const int x = get<1>(s.top())->getInteger();
        s.pop();
        normalize();
        return x;
    }

    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
