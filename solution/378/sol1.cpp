class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=(int)matrix.size();
        long long l=-2e9,r=2e9,ans=-1;
        while (l<=r){
            long long mid=l+(1ll*(r-l)>>1);
            int ans1=0;
            for (int i=0;i<n;++i){
                for (int j=0;j<n;++j){
                    ans1+=matrix[i][j]<=mid;
                }
            }
            if (ans1>=k){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};

