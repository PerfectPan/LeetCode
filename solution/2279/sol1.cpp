class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> res;
        for (int i = 0; i < capacity.size(); ++i) {
            res.emplace_back(capacity[i] - rocks[i]);
        }
        sort(res.begin(), res.end());
        int ans = 0;
        for (int i = 0; i < res.size(); ++i) {
            if (additionalRocks >= res[i]) {
                ans++;
                additionalRocks -= res[i];
            } else {
                break;
            }
        }
        return ans;
    }
};

