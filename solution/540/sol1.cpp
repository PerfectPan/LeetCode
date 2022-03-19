class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    }
};

