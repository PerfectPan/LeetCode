class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int ans = 0 ;
        for (int i = 0; i < nums.size(); ++i) {
            int g = nums[i];
            ans += g == k;
            for (int j = i + 1; j < nums.size(); ++j) {
                g = g / gcd(g, nums[j]) * nums[j];

                if (g == k) {
                    ans++;
                }
                if (g > k) {
                    break;
                }
            }
        }  
        return ans;    
    }
};
