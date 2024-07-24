class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        map<int, int> mp;
        for (int num: nums) {
            mp[num]++;
        }
        int n = moveFrom.size();
        for (int i = 0; i < n; ++i) {
            int t = mp[moveFrom[i]];
            mp.erase(moveFrom[i]);
            mp[moveTo[i]] += t;
        }
        vector<int> vec;
        for (auto& [k, v]: mp) {
            vec.push_back(k);
        }
        return vec;
    }
};
