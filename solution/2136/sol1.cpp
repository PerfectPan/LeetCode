// 按生长时间从大到小排序然后贪心即可
// 假设两个种子 x 和 y，生长时间为 g_x 和 g_y，种植时间为 p_x 和 p_y 且如果 g_x >= g_y
// 先种 x 再种 y，答案为 max(p_x + g_x, p_x + p_y + g_y)
// 先种 y 再种 x，答案为 max(p_y + g_y, p_x + p_y + g_x) = p_x + p_y + g_x
// 可以知道 max(p_x + g_x, p_x + p_y + g_y) <= p_x + p_y + g_x
// 所以第一种方案更优，按这个方案排序即可
// 时间复杂度 O(nlogn)
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<int> ind(n);
        iota(ind.begin(), ind.end(), 0);
        sort(ind.begin(), ind.end(), [&](int x, int y) {
            return growTime[x] > growTime[y];
        });
        int prev = 0, ans = 0;
        for (int id: ind) {
            ans = max(ans, prev + plantTime[id] + growTime[id]);
            prev += plantTime[id];
        }

        return ans;
    }
};
