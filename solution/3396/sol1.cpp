class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int idx = n - 1;
        unordered_set<int> s;
        for (; idx >= 0; --idx) {
            if (!s.count(nums[idx])) {
                s.insert(nums[idx]);
            } else {
                break;
            }
        }
        
        return (idx + 3) / 3;
    }
};
