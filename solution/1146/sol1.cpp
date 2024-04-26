class SnapshotArray {
public:
    vector<pair<int,int> > G[50010]; 
    vector<pair<int,int> > vec;
    int snap_id=-1;
    SnapshotArray(int length) {
        
    }
    
    void set(int index, int val) {
        vec.push_back(make_pair(index,val));
    }
    
    int snap() {
        snap_id+=1;
        for (int i=0;i<(int)vec.size();++i){
            G[vec[i].first].push_back(make_pair(vec[i].second,snap_id));
        }
        vec.clear();
        return snap_id;
    }
    
    int get(int index, int snap_id) {
        int val=0;
        if (G[index].size()==0) return 0;
        if (G[index][0].second>snap_id) return 0;
        if (G[index].back().second<=snap_id) return G[index].back().first;
        int l=0,r=(int)G[index].size()-1,ans=0;
        while (l<=r){
            int mid=l+((r-l)>>1);
            if (G[index][mid].second<=snap_id){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return G[index][ans].first;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
