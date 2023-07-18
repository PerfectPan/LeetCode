// 将询问和线段都按左端点排序，然后优先队列维护，如果弹出来的线段不满足条件，即 r < query[i]，后面询问的线段更加不会满足，所以直接删掉就好了
class Solution {
public:
    struct Seg {
        int l, r;
        bool operator < (const Seg& rhs) const {
            return l < rhs.l;
        }
    };
    struct Query {
        int value, id;
        bool operator < (const Query& rhs) const {
            return value < rhs.value;
        }
    };
    struct Seg2 {
        int l, r;
        bool operator < (const Seg2& rhs) const {
            return r - l + 1 > rhs.r - rhs.l + 1;
        }
    };
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<Seg> seg;
        vector<Query> q;
        for (int i = 0; i < intervals.size(); ++i) {
            seg.push_back((Seg){ intervals[i][0], intervals[i][1] });
        }
        for (int i = 0; i < queries.size(); ++i) {
            q.push_back((Query){ queries[i], i });
        }
        sort(seg.begin(), seg.end());
        sort(q.begin(), q.end());
        priority_queue<Seg2> Q;
        vector<int> ans((int)q.size(), -1);
        for (int i = 0, j = 0; i < q.size(); ++i) {
            int id = q[i].id, value = q[i].value;
            while (j < seg.size() && seg[j].l <= value) {
                Q.push((Seg2){ seg[j].l, seg[j].r });
                j++;
            }

            while (!Q.empty()) {
                auto it = Q.top(); Q.pop();
                if (it.r < value || it.l > value) {
                    continue;
                }
                Q.push(it);
                ans[id] = it.r - it.l + 1;
                break;
            }
        }
        return ans;
    }
};
