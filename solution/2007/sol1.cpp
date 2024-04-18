class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end());
        int n = changed.size();

        vector<int> cnt(100010, 0);
        for (auto& v: changed) {
            cnt[v]++;
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) if (cnt[changed[i]]){
            cnt[changed[i]] -= 1;
            ans.push_back(changed[i]);
            if (changed[i] * 2 <= 100000) {
                if (cnt[changed[i] * 2] == 0) {
                    return {};
                }
                cnt[changed[i] * 2] -= 1;
            } else {
                return {};
            }
        }

        return ans;
    }
};
