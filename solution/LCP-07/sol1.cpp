class Solution {
public:
    int cnt[15][15],cnt2[15][15],cnt3[15][15];
    int numWays(int n, vector<vector<int>>& relation, int k) {
        for (int i=0;i<(int)relation.size();++i){
            int x=relation[i][0],y=relation[i][1];
            cnt[x][y]++;
        }
        memset(cnt2,0,sizeof(cnt2));
        for (int i=0;i<n;++i) cnt2[i][i]=1;
        for (int i=1;i<=k;++i){
            memset(cnt3,0,sizeof(cnt3));
            for (int j=0;j<n;++j){
                for (int kk=0;kk<n;++kk){
                    for (int l=0;l<n;++l){
                        cnt3[kk][l]+=cnt2[kk][j]*cnt[j][l];
                    }   
                }
            }
            for (int j=0;j<n;++j){
                for (int l=0;l<n;++l){
                    cnt2[j][l]=cnt3[j][l];
                }
            }
        }
        return cnt2[0][n-1];
    }
};

