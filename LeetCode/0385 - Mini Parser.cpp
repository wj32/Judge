/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger recurse(const string& s, size_t* index) {
        if (s[*index] == '[') {
            (*index)++;
            NestedInteger ni;
            while (*index < s.size()) {
                if (s[*index] == ']') {
                    (*index)++;
                    break;
                }
                ni.add(recurse(s, index));
                if (s[*index] == ',') {
                    (*index)++;
                }
            }
            return ni;
        }
        else {
            int sign = 1;
            int number = 0;
            if (s[*index] == '-') {
                sign = -1;
                (*index)++;
            }
            while ((*index < s.size()) && (s[*index] >= '0') && (s[*index] <= '9')) {
                number *= 10;
                number += s[*index] - '0';
                (*index)++;
            }
            return NestedInteger(sign * number);
        }
    }

    NestedInteger deserialize(string s) {
        size_t index = 0;
        return recurse(s, &index);
    }
};
