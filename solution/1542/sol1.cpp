class Solution {
public:
    int longestAwesome(string s) {
        vector<int> mp(1 << 11, -1);
        int pre = 0, ans = 0;
        mp[0] = 0;
        for (int i = 0; i < s.length(); ++i) {
            pre ^= 1 << (s[i] - '0');
            if (mp[pre] != -1) {
                ans = max(ans, i + 1 - mp[pre]);
            }
            for (int j = 0; j < 10; ++j) {
                if (mp[pre ^ (1 << j)] != -1) {
                    ans = max(ans, i + 1 - mp[pre ^ (1 << j)]);
                }
            }

            if (mp[pre] == -1) {
                mp[pre] = i + 1;
            }
        }

        return ans;
    }
};
