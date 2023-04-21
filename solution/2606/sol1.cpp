// 维护前缀最小和即可，每次遍历到下标 i，答案就是 max{pre[i] - min_pre{0..i}}
class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int v[26];
        for (int i = 0; i < 26; ++i) {
            v[i] = i + 1;
        }
        for (int i = 0; i < chars.size(); ++i) {
            v[chars[i] - 'a'] = vals[i];
        }
        
        int pre = 0, mn = 0, ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            pre += v[s[i] - 'a'];
            ans = max(ans, pre - mn);
            mn = min(mn, pre);
        }
        return ans;
    }
};
