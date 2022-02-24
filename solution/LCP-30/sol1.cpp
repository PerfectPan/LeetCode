class Solution {
public:
    int magicTower(vector<int>& nums) {
        long long res = 1;
        for (int i = 0; i < nums.size(); ++i) {
          res += nums[i];
        }
        if (res < 0) {
          return -1;
        }
        priority_queue<long long, vector<long long>, greater<long long>> Q;
        int ans = 0;
        res = 1;
        for (int i = 0; i < nums.size(); ++i) {
          res += nums[i];
          if (nums[i] < 0) {
            Q.push(nums[i]);
          }

          if (res <= 0) {
            while (!Q.empty()) {
              auto x = Q.top(); Q.pop();
              res -= x;
              ans += 1;
              if (res > 0) {
                break;
              }
            }
          }
        }
        return ans;
    }
};

