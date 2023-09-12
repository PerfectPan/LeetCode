class Solution {
public:
    #define N 105
    bool vis[N][N];
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        for (int i=0;i<(int)prerequisites.size();++i){
            vis[prerequisites[i][0]][prerequisites[i][1]]=1;
        }        
        for (int k=0;k<n;++k){
            for (int i=0;i<n;++i){
                for (int j=0;j<n;++j){
                    vis[i][j]|=vis[i][k] && vis[k][j];
                }
            }
        }
        vector<bool> res;
        for (int i=0;i<(int)queries.size();++i){
            res.push_back(vis[queries[i][0]][queries[i][1]]);
        }
        return res;
    }
};
