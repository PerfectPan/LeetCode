// 通过循环节可以找出所有必须相等的位置，然后贪心的考虑一定是让这些位置的数都变成中位数才能使答案最优
class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        int n = arr.size();
        int vis[n];
        memset(vis, 0, sizeof(vis));
        long long ans = 0;
        for (int i = 0; i < arr.size(); ++i) if (!vis[i]) {
            int j = i;
            vector<int> rec;
            while (!vis[j]) {
                rec.emplace_back(arr[j]);
                vis[j] = 1;
                j = (j + k) % n;
            }
            sort(rec.begin(), rec.end());
            int len = (int)rec.size();
            int mid = len / 2;
            long long target = rec[mid];
            if (len % 2 == 0) {
                target = (target + rec[mid - 1]) / 2;
            }

            for (int j = 0; j < rec.size(); ++j) {
                ans += abs(rec[j] - target);
            }
        }
        return ans;
    }
};
