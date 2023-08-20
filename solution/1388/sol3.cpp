// 基于反悔的贪心，感觉这辈子都想不到系列。。
// 优先队列维护大根堆，每次弹出一个数以后要删除左右两边的数，然后为了可以反悔，要重新推一个左右两边数之和 - 当前数的值进队列，这样下次如果选这个数
// 就相当于反悔了选了左右两边两个数
// 时间复杂度 O(nlogn)
struct Node {
    int value, l, r;
};
// 基于 vector 实现双向链表
vector<Node> a;

struct Id {
    int id;
    bool operator < (const Id& rhs) const {
        return a[id].value < a[rhs.id].value;
    }
};

void del(int i) {
    // 这里不需要更新 i 的左右指针，因为 i 已经不会再被用了
    a[a[i].l].r = a[i].r;
    a[a[i].r].l = a[i].l;
}

class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int k = n / 3;
        a.clear();
        for (int i = 0; i < n; ++i) {
            a.emplace_back(Node{slices[i], (i - 1 + n) % n , (i + 1) % n});
        }
        priority_queue<Id> Q;
        // 标记某一序号是否能够被选取
        vector<int> vis(n, 1);
        for (int i = 0; i < n; ++i) {
            Q.push(Id{i});
        }
        int cnt = 0, ans = 0;
        while (cnt < k) {
            int id = Q.top().id; Q.pop();
            if (vis[id]) {
                cnt++;
                ans += a[id].value;
                int pre = a[id].l;
                int nxt = a[id].r;
                vis[pre] = vis[nxt] = 0;
                a[id].value = a[pre].value + a[nxt].value - a[id].value;
                Q.push(Id{id});
                // 删除左右序号
                del(pre);
                del(nxt);
            }
        }
        return ans;
    }
};
