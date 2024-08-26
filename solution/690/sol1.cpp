/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> employee_map;

        for (auto e: employees) {
            employee_map[e->id] = e;
        }

        auto dfs = [&](auto&& dfs, int u) -> int {
            int res = employee_map[u]->importance;
            for (auto v: employee_map[u]->subordinates) {
                res += dfs(dfs, v);
            }
            return res;
        };

        return dfs(dfs, id);
    }
};
