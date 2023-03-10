// (pre[i] - x) % p = pre[j] % p
// 哈希表存前缀和
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        vector<int> pre(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            pre[i + 1] = (nums[i] + pre[i]) % p;
        }

        if (pre[n] == 0) {
            return 0;
        }
        
        int diff = pre[n];
        map<int, int> mp;

        int ans = n;
        for (int i = 0; i <= n; ++i) {
            mp[pre[i]] = i;
            int t1 = (pre[i] - diff + p) % p;

            if (mp.count(t1)) {
                ans = min(ans, i - mp[t1]);
            }
        }

        return ans < n ? ans : -1;
    }
};
