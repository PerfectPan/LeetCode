// 从前往后扫，用一个数据结构记录已经下过雨的湖泊和下标，如果碰到第二次，说明需要第一次和第二次之间最早没下雨的时候把这个湖泊的水抽走才能防止洪水
// 动态维护没下雨且没操作过的日子，二分找符合条件的位置即可
// 最早没下雨这个正确性可以简单想一下，假设两个日子 x < y，x 能抽干的湖泊数量一定是小于等于 y 的，所以选择靠后的日子一定不会让答案更优
// 时间复杂度 O(nlogn)
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);
        unordered_map<int, int> mp;
        set<int> S;
        for (int i = 0; i < n; ++i) {
            if (rains[i] > 0) {
                if (mp.count(rains[i])) {
                    auto it = S.lower_bound(mp[rains[i]]);
                    if (it == S.end()) {
                        return {};
                    }
                    ans[*it] = rains[i];
                    S.erase(it);
                }

                mp[rains[i]] = i;
                ans[i] = -1;
            } else {
                S.insert(i);
            }
        }
        return ans;
    }
};
