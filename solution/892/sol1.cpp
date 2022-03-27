class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int ans=0,n=(int)grid.size(),m=(int)grid[0].size();
        for (int i=0;i<n;++i){
            for (int j=0;j<m;++j){
                int t=grid[i][j];
                if (t==1) ans+=6;
                else if (t==2) ans+=10;
                else if (t>0){
                    ans+=10;
                    t-=2;
                    ans+=t*4;
                }
            }
        }
        for (int i=0;i<n;++i){
            for (int j=1;j<m;++j){
                ans-=min(grid[i][j],grid[i][j-1])*2;
            }
        }
        for (int i=0;i<m;++i){
            for (int j=1;j<n;++j){
                ans-=min(grid[j][i],grid[j-1][i])*2;
            }
        }
        return ans;
    }
};

