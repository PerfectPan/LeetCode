class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int mx=min(n,m);
        int ans=1;
        for (int i=2;i<=mx;++i){
            bool F=0;
            for (int j=0;j+i-1<n;++j){
                for (int k=0;k+i-1<m;++k){
                    int x=j,y=k;
                    int ex=j+i-1,ey=k+i-1;

                    int pre=-1;
                    bool f=1;
                    for (int a=x;a<=ex;++a){
                        int res=0;
                        for (int b=y;b<=ey;++b){
                            res+=grid[a][b];
                        }
                        if (pre==-1) pre=res;
                        else if (pre!=res){
                            f=0;
                            break;
                        }
                    }
                    if (!f){
                        continue;
                    }
                    // pre=-1;
                    for (int b=y;b<=ey;++b){
                        int res=0;
                        for (int a=x;a<=ex;++a){
                            res+=grid[a][b];
                        }
                        if (pre==-1) pre=res;
                        else if (pre!=res){
                            f=0;
                            break;
                        }
                    }
                    if (!f){
                        continue;
                    }

                    int A=0,B=0;
                    for (int a=x,b=y;a<=ex;++a,++b){
                        A+=grid[a][b];
                    }
                    for (int a=x,b=ey;a<=ex;++a,--b){
                        B+=grid[a][b];
                    }
                    if (A==B && A==pre){
                        F=1;
                        j=n+1;
                        k=m+1;
                    }
                }
            }
            if (F){
                ans=i;
            }
        }
        return ans;
    }
};

