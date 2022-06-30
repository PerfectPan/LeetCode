class Solution {
public:
    int res = 1e9;
    bool used[10];
    void dfs(int i, vector<int>& r, int j, vector<int>& cookies, int k) {
        if (i == (int)cookies.size()) {
            res = min(res, *max_element(r.begin(), r.end()));
            return;
        }
        for (int ii = 0; ii < cookies.size(); ++ii) {
            if (!used[ii]) {
                r[(int)r.size() - 1] += cookies[ii];
                used[ii] = true;
                dfs(i + 1, r, j, cookies, k);
                r[(int)r.size() - 1] -= cookies[ii];        
                used[ii] = false;

                if (j < k) {
                    r.push_back(cookies[ii]);
                    used[ii] = true;
                    dfs(i + 1, r, j + 1, cookies, k);
                    used[ii] = false;
                    r.pop_back();
                }
            }
        } 
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> ans;
        ans.push_back(0);
        dfs(0, ans, 1, cookies, k);
        return res;
    }
};

