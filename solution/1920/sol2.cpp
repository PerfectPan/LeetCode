class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int x = nums[i];
            if (x < 0) {
                continue;
            }
            int cur = i;
            while (nums[cur] != i) {
                int nxt = nums[cur];
                nums[cur] = ~nums[nxt];
                cur = nxt;
            }
            nums[cur] = ~x;
        }

        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = ~nums[i];
        }
        return nums;
    }
};
