class Solution {
public:
    int countLargestGroup(int n) {
        map<int, int> mp;
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            int x = i, ans = 0;
            while (x) {
                ans += x % 10;
                x /= 10;
            }
            mp[ans]++;
            res = max(res, mp[ans]);
        }
        int cnt = 0;
        for (auto it: mp) {
            cnt += it.second == res;
        }
        return cnt;
    }
};
