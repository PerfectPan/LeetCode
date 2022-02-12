class Solution {
    #define N 200005
    pair<int, int> seg[N];
    unordered_map<int, int> mp;
    int lis[N];
    int cap[N], filled[N];
    int c[N], mm;
    inline int lowbit(int x){
        return x & (-x);
    }
    void add(int k, int x) {
        for (; k <= mm; k += lowbit(k)) {
            c[k] += x;
        }
    }
    int query(int r) {
        int res = 0;
        for (; r > 0; r -= lowbit(r)) {
            res += c[r];
        }
        return res;
    }
    int fa[N];
    int Find(int x) { return x == fa[x] ? x: fa[x] = Find(fa[x]); }
public:
    int processTasks(vector<vector<int>>& tasks) {
        int tot = 0, n = tasks.size();
        // 离散化
        for (int i = 1; i <= n; ++i){
            auto& q = tasks[i - 1];
            ++q[1];
            seg[++tot].first = q[0], seg[tot].second = i;
            seg[++tot].first = q[1], seg[tot].second = -i;
        }
        sort(seg + 1, seg + tot + 1);
        int idx = 0;
        for (int i = 1, j; i <= tot; i = j) {
            j = i;
            for (; j <= tot && seg[i].first == seg[j].first; ) {
                ++j;
            }
            ++idx;
            mp[seg[i].first] = idx;
            lis[idx] = seg[i].first;
        }

        // 计算小线段的容量
        cap[0] = 0;
        for (int i = 1; i < idx; ++i) {
            cap[i] = lis[i + 1] - lis[i];
            fa[i] = i;
        }

        fa[0] = 0;

        // 总共有 bb - 1 个小线段
        mm = idx - 1;
        for (int i = 1; i <= tot; ++i){
            if (seg[i].second < 0){
                int id = -seg[i].second - 1;
                int lb = tasks[id][0], rb = tasks[id][1];
                int lbid = mp[lb], rbid = mp[rb];
                int res = query(rbid - 1) - query(lbid - 1);
                if (res >= tasks[id][2]) {
                    continue;
                }
                
                int pos = fa[rbid - 1];
                int need = tasks[id][2] - res;

                // 逐步装入开机时间
                for ( ; ; ) {
                    int left = cap[pos] - filled[pos];
                    if (left > need){
                        filled[pos] += need;
                        add(pos, need);
                        break;
                    } else if (left == need){
                        filled[pos] += need;
                        add(pos, need);
                        fa[pos] = fa[pos - 1];
                        break;
                    } else {
                        filled[pos] += left;
                        need -= left;
                        add(pos, left);
                        fa[pos] = fa[pos - 1];
                        pos = Find(pos);
                    }
                }
            }
        }
        
        return query(mm);
    }
};

