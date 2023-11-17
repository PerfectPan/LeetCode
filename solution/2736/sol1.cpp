// 询问离线，按 x 端点倒排，把 nums 数组按 nums1 倒排，权值线段树维护 nums2 为下标的 nums1 + nums2 的区间最大值
// 每次碰到一个询问，把大于等于这个询问 x 的 nums 都加入到权值线段树
// 这样就是查询大于等于 y 的 nums1 + nums2 的最大值，线段树查询即可
// 注意到 nums2 的值域很大，需要离散化
// 时间复杂度 O((n + m)logn)
class Solution {
public:
    int mx[400000 + 10];
    #define lson root << 1, l, mid
    #define rson root << 1 | 1, mid + 1, r
    void pushup(int root) {
        mx[root] = max(mx[root << 1], mx[root << 1 | 1]);
    }
    void add(int root, int l, int r, int x, int v) {
        if (l == r) {
            mx[root] = max(mx[root], v);
            return;
        }
        int mid = l + ((r - l) >> 1);
        if (x <= mid) add(lson, x, v);
        if (mid < x) add(rson, x, v);
        pushup(root);
    }
    int query(int root, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return mx[root];
        }
        int mid = l + ((r - l) >> 1);
        int ret = -1;
        if (L <= mid) ret = max(ret, query(lson, L, R));
        if (mid < R) ret = max(ret, query(rson, L, R));
        return ret;
    }
    void build(int root, int l, int r) {
        if (l == r) {
            mx[root] = -1;
            return;
        }
        int mid = l + ((r - l) >> 1);
        build(lson);
        build(rson);
        pushup(root);
    }
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size();
        int m = queries.size();
        vector<int> id(m), idn(n);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](int x, int y) {
            return queries[x][0] > queries[y][0];
        });

        iota(idn.begin(), idn.end(), 0);
        sort(idn.begin(), idn.end(), [&](int x, int y) {
            return nums1[x] > nums1[y];
        });
        vector<int> q;
        for (int num: nums2) {
            q.push_back(num);
        }
        sort(q.begin(), q.end());
        q.erase(unique(q.begin(), q.end()), q.end());
        int seg_size = q.size();
        build(1, 1, seg_size);
        vector<int> ans(m, 0);
        for (int i = 0, j = 0; i < m; ++i) {
            int idx = id[i];
            while (j < n && nums1[idn[j]] >= queries[idx][0]) {
                int py = lower_bound(q.begin(), q.end(), nums2[idn[j]]) - q.begin() + 1;
                add(1, 1, seg_size, py, nums1[idn[j]] + nums2[idn[j]]);
                j++;
            }
            int pos = lower_bound(q.begin(), q.end(), queries[idx][1]) - q.begin() + 1;
            if (pos == n + 1) {
                ans[idx] = -1;
            } else {
                ans[idx] = query(1, 1, seg_size, pos, q.size());
            }
        }
        return ans;
    }
};
