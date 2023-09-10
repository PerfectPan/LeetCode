class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> d(numCourses, 0);
        vector<int> G[numCourses];

        for (auto& prerequisite: prerequisites) {
            int u = prerequisite[0], v = prerequisite[1];
            d[u]++;
            G[v].push_back(u);
        }

        queue<int> Q;
        vector<int> res;

        for (int i = 0; i < numCourses; ++i) {
            if (d[i] == 0) {
                Q.push(i);
            }
        }

        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            res.push_back(u);
            for (int v: G[u]) {
                if (--d[v] == 0) {
                    Q.push(v);
                }
            }
        }

        return res.size() == numCourses ? res : vector<int>{};
    }
};
