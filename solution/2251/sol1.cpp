// 将点离散化以后用差分打标记，最后求出前缀和即可知道每个 people 的答案了
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> vec;
        for (const auto& flower: flowers) {
            vec.push_back(flower[0]);
            vec.push_back(flower[1] + 1);
        }
        for (int p: people) {
            vec.push_back(p);
        }

        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());

        vector<int> cnt(vec.size(), 0);
        for (const auto& flower: flowers) {
            int l = flower[0], r = flower[1] + 1;
            int rl = lower_bound(vec.begin(), vec.end(), l) - vec.begin();
            int rr = lower_bound(vec.begin(), vec.end(), r) - vec.begin();
            cnt[rl] += 1;
            cnt[rr] -= 1;
        }

        for (int i = 1; i < vec.size(); ++i) {
            cnt[i] += cnt[i - 1];
        }

        vector<int> ans(people.size());
        for (int i = 0; i < people.size(); ++i) {
            int rp = lower_bound(vec.begin(), vec.end(), people[i]) - vec.begin();
            ans[i] = cnt[rp];
        }
        
        return ans;
    }
};
