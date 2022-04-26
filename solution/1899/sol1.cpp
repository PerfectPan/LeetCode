class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> res{0,0,0};
        int X=target[0],Y=target[1],Z=target[2];
        for (auto& tri: triplets) {
            int a=tri[0],b=tri[1],c=tri[2];
            if (a<=X && b<=Y && c<=Z){
                res[0]=max(res[0],a);
                res[1]=max(res[1],b);
                res[2]=max(res[2],c);
            }
        }
        return res[0]==X && res[1]==Y && res[2]==Z;
    }
};

