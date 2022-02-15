class Solution {
public:
    #define P 1000000007
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
      sort(staple.begin(),staple.end());
      sort(drinks.begin(),drinks.end());

      int ans=0;
      for (int i=0;i<drinks.size();++i){
        int y=drinks[i];
        int l=x-y;
        if (l<=0) continue;
        int L=0,R=(int)staple.size()-1,res=-1;
        while (L<=R){
          int mid=(L+R)>>1;
          if (staple[mid]<=l){
            res=mid;
            L=mid+1;
          } else R = mid - 1;
        }
        (ans += res + 1)%=P;
      }
      return ans;
    }
};

