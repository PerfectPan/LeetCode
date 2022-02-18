class Solution {
public:
    #define N 10010
    int A[N],B[N],C[N];
    vector<int> getTriggerTime(vector<vector<int>>& increase, vector<vector<int>>& requirements) {
        A[0]=B[0]=C[0]=0;
        for (int i=0;i<(int)increase.size();++i){
            if (i!=0){
                A[i+1]=A[i];
                B[i+1]=B[i];
                C[i+1]=C[i];
            }
            A[i+1]+=increase[i][0];
            B[i+1]+=increase[i][1];
            C[i+1]+=increase[i][2];
        }
        vector<int> res;
        for (int i=0;i<(int)requirements.size();++i){
            int a=requirements[i][0],b=requirements[i][1],c=requirements[i][2];
            int L=0,R=(int)increase.size(),ans=-1;
            while (L<=R){
                int mid=L+((R-L)>>1);
                if (A[mid]>=a && B[mid]>=b && C[mid]>=c){
                    ans=mid;
                    R=mid-1;
                }
                else L=mid+1;
            }
            res.push_back(ans);
        }
        return res;
    }
};

