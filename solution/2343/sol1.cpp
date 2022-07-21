class Solution {
public:
    struct Query {
        int k,t,id;
        bool operator<(const Query& rhs)const {
            return t > rhs.t;
        }
    };
    struct Item {
        string s;
        int idx;
        bool operator<(const Item& rhs)const {
            if (s == rhs.s) return idx < rhs.idx;
            return s < rhs.s;
        }
    };
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(), 0);
        vector<Query> vec;
        int cnt = 0;
        for (auto& q: queries) {
            vec.emplace_back((Query){q[0], q[1], cnt++});
        }
        sort(vec.begin(), vec.end());
        vector<Item> it;
        for (int i = 0; i < nums.size(); ++i) {
            it.emplace_back((Item){nums[i], i});
        }
        
        for (int i = 0; i < vec.size(); ++i) {
            int t = vec[i].t;
            int k = vec[i].k;
            int id = vec[i].id;
            if (i == 0 || t != vec[i-1].t) {
                int pn = 0;
                int len = it[0].s.length();
                for (int j = 0; j < it.size(); ++j) {
                    it[j].s = it[j].s.substr(len - t);
                }
                sort(it.begin(), it.end());
            }
            ans[id] = it[k-1].idx;
        }
        return ans;
    }
};

