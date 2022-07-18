class Solution {
public:
    int cnt[105];
    vector<int> numberOfPairs(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            cnt[nums[i]] += 1;
        }
        int sum = 0, left = 0;
        for (int i = 0; i <= 100; ++i) {
            sum += cnt[i] / 2;
            left += cnt[i] % 2;
        }
        return vector<int>{sum, left};
    }
};

