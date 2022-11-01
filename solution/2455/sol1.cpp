class Solution {
public:
    int averageValue(vector<int>& nums) {
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 3 == 0 && nums[i] % 2 == 0) {
                ans += nums[i];
                cnt += 1;
            }
        }    
        return cnt == 0 ? 0 : ans / cnt;
    }
};
