class Solution {
public:
    bool check(string command,int x,int y){
        int tx=0,ty=0;
        for (int i=0;i<(int)command.size();++i){
            if (command[i]=='U') ty+=1;
            else tx+=1;
        }
        int l=0,r=1e9/max(tx,ty),ans=0;
        while (l<=r){
            int mid=l+((r-l)>>1);
            if (mid*tx<=x && mid*ty<=y){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        int cx=tx*ans,cy=ty*ans;
        if (cx==x && cy==y) return 1;
        for (int i=0;i<(int)command.size();++i){
            if (command[i]=='U') cy+=1;
            else cx+=1;
            if (cx==x && cy==y) return 1;
            if (cx>x || cy>y) return 0;
        }
        return 1;
    }
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        for (int i=0;i<(int)obstacles.size();++i){
            int tx=obstacles[i][0],ty=obstacles[i][1];
            if (tx<=x && ty<=y && check(command,tx,ty)) return false;
        }
        return check(command,x,y);
    }
};

