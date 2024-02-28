// 观察是任意节点为根结点的子树到叶子结点的值都是一样
// 然后看叶子结点的兄弟节点 x 和 y，贪心的加 abs(y - x) 即可，然后父亲节点值是 z，z 的值可以认为是 z + max(x, y)，然后再看父亲节点和其兄弟节点
// 按同样的方式贪心计算，直到根结点即可
class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int ans = 0;
        for (int i = n - 2; i > 0; i -= 2) {
            ans += abs(cost[i] - cost[i + 1]);
            cost[i / 2] += max(cost[i], cost[i + 1]);
        }
        return ans;
    }
};
