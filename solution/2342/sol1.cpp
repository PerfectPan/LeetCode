class Solution {
public:
    map<int, int> mp;
    int solve(int x) {
        int cnt = 0;
        while (x > 0) {
            cnt+=x%10;
            x /= 10;
        }
        return cnt;
    }
    int maximumSum(vector<int>& nums) {
        int res = -1;
        for (auto& num: nums) {
            int bi = solve(num);
            if (mp.find(bi)!=mp.end()){
                res = max(res, num + mp[bi]);
                mp[bi] = max(mp[bi], num);
            }else{
                mp[bi] = num;
            }
        }        
        return res;
    }
};

