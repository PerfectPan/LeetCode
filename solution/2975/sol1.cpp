class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        set<int> S;
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        for (int i = 0; i < hFences.size(); ++i) {
            for (int j = i + 1; j < hFences.size(); ++j) {
                S.insert(hFences[j] - hFences[i]);
            }
        }
        int ans = -1;
        for (int i = 0; i < vFences.size(); ++i) {
            for (int j = i + 1; j < vFences.size(); ++j) {
                int diff = vFences[j] - vFences[i];
                if (S.count(diff)) {
                    ans = max(ans, diff);
                }
            }
        }
        return ans == -1 ? ans : 1LL * ans * ans % 1000000007;
    }
};
