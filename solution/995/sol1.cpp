class Solution {
public:
    int tag[30000+10];
    int minKBitFlips(vector<int>& A, int K) {
        int ans=0;
        for (int i=0;i<(int)A.size();++i){
            if (i) tag[i]^=tag[i-1];
            if (A[i]^tag[i]==0){
                if (i+K-1>=(int)A.size()) return -1;
                ans++;
                tag[i]^=1;
                tag[i+K]^=1;
            }
        }
        return ans;
    }
};

