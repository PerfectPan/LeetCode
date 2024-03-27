// 把有交集的区间合并后剩下不相交的组数为 x，答案就是 2^x，因为每个组可以选择放在 A 或 B
// 合并的方法就是对区间按左端点排序后维护右端点最大值即可，如果当前区间左端点大于最大的右端点就说明产生新的组了
class Solution {
public:
    int P = 1e9 + 7;
    int countWays(vector<vector<int>>& ranges) {
        int n = ranges.size();
        sort(ranges.begin(), ranges.end());
        int res = 2;
        int R = ranges[0][1];
        for (int i = 1; i < n; ++i) {
            if (ranges[i][0] > R) {
                res = res * 2LL % P;   
            }
            R = max(R, ranges[i][1]);
        }
        return res;
    }
};
