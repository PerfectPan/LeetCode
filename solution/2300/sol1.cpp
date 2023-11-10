// 排序以后双指针
// 还有一种解法是值域不大，直接开数组统计前缀和，针对每个 spell，计算出最大的可以成功的数，然后用前缀和 O(1) 统计
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        vector<int> idx(n, 0);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int x, int y) {
            return spells[x] < spells[y];
        });
        sort(potions.begin(), potions.end(), greater<int>());
        int i = 0;
        vector<int> ans(n, 0);
        for (auto& id: idx) {
            while (i < potions.size() && 1LL * spells[id] * potions[i] >= success) {
                i++;
            }
            ans[id] = i;
        }

        return ans;
    }
};
