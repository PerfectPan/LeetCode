class Solution {
public:
    map<int, int>mp;
    int subarraysDivByK(vector<int>& A, int K) {
        int pre=0,ans=0;
        mp[0]=1;
        for (int i=0;i<(int)A.size();++i){
            pre=((pre+A[i])%K+K)%K;
            ans+=mp[pre];
            mp[pre]++;
        }
        return ans;
    }
};

