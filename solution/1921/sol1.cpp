// 算出来每个怪物到达城市的时间（上取整），然后从小到大排序
// 从小到大贪心地砍即可，我们是每一分钟砍一次，假设当前时间是 T，如果怪物的时间 x 已经小于等于 T，说明已经阻止不了了，包括后面的怪物，返回结果即可
// 时间复杂度 O(n)
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        for (int i = 0; i < dist.size(); ++i) {
            dist[i] = (dist[i] + speed[i] - 1) / speed[i];
        }
        sort(dist.begin(), dist.end());

        int ans = 0;
        for (int i = 0; i < dist.size(); ++i) {
            if (dist[i] <= i) {
                return i;
            }
        }
        return dist.size();
    }
};
