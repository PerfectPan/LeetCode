// 对 difficulty 排序以后维护前缀最大收益 prev，对每个工人二分找小于等于 worker[i] 的工作 j，答案就是 prev[j]
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<int> id(n, 0);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](int x, int y) {
            return difficulty[x] < difficulty[y];
        });
        vector<int> prev(n, 0);
        for (int i = 0; i < n; ++i) {
            prev[i] = i == 0 ? profit[id[i]] : max(prev[i - 1], profit[id[i]]);
        }

        sort(difficulty.begin(), difficulty.end());

        int res = 0;
        for (int p: worker) {
            int l = 0, r = n - 1, ans = -1;
            while (l <= r) {
                int mid = l + ((r - l) >> 1);
                if (difficulty[mid] <= p) {
                    ans = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            if (ans != -1) {
                res += prev[ans];
            }
        }

        return res;
    }
};
