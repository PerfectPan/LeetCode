class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        bool flag = false;
        int n=nums.size();
        for (int i=0;i<n;++i){
            bool f=true;
            for (int j=1;j<n;++j)if(j!=i){
                if (j-1!=i){
                    if (nums[j]<=nums[j-1]){
                        f=false;
                        break;
                    }
                }else{
                    if (j-2>=0 && nums[j]<=nums[j-2]){
                        f=false;
                        break;
                    }
                }
            }
            if (f){
                return true;
            }
        }
        return false;
    }
};

