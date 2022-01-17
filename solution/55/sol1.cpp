class Solution {
public:
    bool canJump(vector<int>& nums) {
        int r=nums[0];
        for (int i=1;i<(int)nums.size();++i){
            int step=i+nums[i];
            if (i<=r) r=max(r,step);
        }
        return r>=(int)nums.size()-1;
    }
};


