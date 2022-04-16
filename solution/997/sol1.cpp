class Solution {
public:
    int deg[1000+10][2];
    int findJudge(int N, vector<vector<int>>& trust) {
        for (int i=0;i<(int)trust.size();++i){
            deg[trust[i][0]][0]++;
            deg[trust[i][1]][1]++;
        }
        int cnt=0;
        for (int i=1;i<=N;++i){
            if (deg[i][1]==N-1 && deg[i][0]==0) cnt++;
        } 
        if (cnt!=1) return -1;
        for (int i=1;i<=N;++i){
            if (deg[i][1]==N-1 && deg[i][0]==0) return i;
        } 
        return 0;
    }
};

