/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int totalImportance(const unordered_map<int, const Employee*>& m, int id) {
        const auto employee = m.find(id)->second;
        int sum = employee->importance;
        for (const auto subordinate : employee->subordinates) {
            sum += totalImportance(m, subordinate);
        }
        return sum;
    }

    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, const Employee*> m;
        for (const auto employee : employees) {
            m[employee->id] = employee;
        }
        return totalImportance(m, id);
    }
};
