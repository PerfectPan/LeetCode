class Solution {
public:
    set<pair<int,int> >S;
    bool has[2000],vis[2000];
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        S.clear();
        memset(has,0,sizeof(has));
        memset(vis,0,sizeof(vis));
        for (auto x:initialBoxes) S.insert(make_pair(!status[x],x));
        int res=0;
        while (!S.empty()){
            pair<int,int> x=*S.begin();
            S.erase(S.begin());
            if (vis[x.second]) continue;
            vis[x.second]=1;
            if (x.first==1) break;
            res+=candies[x.second];
            for (auto k:keys[x.second]){
                has[k]=1;
                if (S.find(make_pair(1,k))!=S.end()){
                    auto it=S.find(make_pair(1,k));
                    S.erase(it);
                    S.insert(make_pair(0,k));
                }
            }
            for (auto k:containedBoxes[x.second])if(!vis[k]){
                if (status[k]==1 || has[k]) S.insert(make_pair(0,k));
                else S.insert(make_pair(1,k));
            }
        }
        return res;
    }
};
