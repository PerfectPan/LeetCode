class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for (int i = 0, j = n - 1; i <= j; ++i, --j) {
            if (i == j) {
                ans += nums[i];
            } else {
                ans += stoi(to_string(nums[i]) + to_string(nums[j]));
            }
        }      
        return ans;
    }
};
