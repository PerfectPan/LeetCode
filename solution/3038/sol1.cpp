class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int cnt = 0;
        int previous = -1;
        for (int i = 0; i + 1 < nums.size(); i += 2) {
            int sum = nums[i] + nums[i + 1];
            if (previous == -1 || previous == sum) {
                cnt++;
                previous = sum;
            } else {
                break;
            }
        }   
        return cnt;
    }
};
