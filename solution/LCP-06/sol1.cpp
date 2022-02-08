class Solution {
public:
    int minCount(vector<int>& coins) {
        int ans=0;
        for (auto x:coins){
            ans+=(x+1)/2;
        }
        return ans;
    }
};

