class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int x=0,n=nums.size();
        for (int i=0;i<(int)nums.size();++i) x^=nums[i];
        return x==0 || n%2==0;
    }
};

