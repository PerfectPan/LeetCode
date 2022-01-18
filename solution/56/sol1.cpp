class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if ((int)intervals.size() == 0) return intervals;
        sort(intervals.begin(),intervals.end());
        int l = intervals[0][0], r = intervals[0][1];
        vector<vector<int>> res;
        for (int i=1;i<(int)intervals.size();++i){
            int L=intervals[i][0],R=intervals[i][1];
            if (L>r){
                vector<int> seg;
                seg.push_back(l);
                seg.push_back(r);
                res.push_back(seg);
                l=L,r=R;
            }
            else{
                r=max(r,R);
            }
        }
        vector<int> seg;
        seg.push_back(l);
        seg.push_back(r);
        res.push_back(seg);
        return res;
    }
};

