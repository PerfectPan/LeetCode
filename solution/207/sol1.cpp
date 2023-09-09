class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> d(numCourses, 0);
        vector<int> G[numCourses];

        for (auto& prerequisite: prerequisites) {
            int u = prerequisite[0], v = prerequisite[1];
            d[u]++;
            G[v].push_back(u);
        }

        queue<int> Q;
        int res = 0;
        for (int i = 0; i < numCourses; ++i) {
            if (d[i] == 0) {
                Q.push(i);
                res++;
            }
        }

        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            for (int v: G[u]) {
                if (--d[v] == 0) {
                    Q.push(v);
                    res++;
                }
            }
        }

        return res == numCourses;
    }
};
