class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
		int n = nums.size();
		int S = 1 << n;
		int res = 0;
		for (int i = 0; i < S; ++i) {
			int tot = 0;
			for (int j = 0; j < n; ++j) if (i & (1 << j)) {
				tot ^= nums[j];
			}
			res += tot;
		}
		return res;
    }
};
