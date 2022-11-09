class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i + 1< nums.size(); ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] <<= 1;
                nums[i + 1] = 0;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                res.push_back(nums[i]);
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};
