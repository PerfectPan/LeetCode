class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if ((int)strs.size()==0) return "";
        int lenmn=(int)strs[0].length();
        for (int i=1;i<(int)strs.size();++i) lenmn=min(lenmn,(int)strs[i].length());
        int l=1,r=lenmn,ans=-1;
        while (l<=r){
            int mid=l+((r-l)>>1);
            bool flag=0;
            string s=strs[0].substr(0,mid);
            for (int i=1;i<(int)strs.size();++i){
                if (s!=strs[i].substr(0,mid)){
                    flag=1;
                    break;
                }
            }
            if (!flag){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        if (ans==-1) return "";
        else return strs[0].substr(0,ans);
    }
};

