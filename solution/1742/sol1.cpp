class Solution {
public:
  int countBalls(int lowLimit, int highLimit) {
    vector<int> ans(100, 0);
    for (int i = lowLimit; i <= highLimit; ++i) {
      int tot = 0;
      int num = i;
      while (num) {
        tot += num % 10;
        num /= 10;
      }
      ans[tot]++;
    }
    return *max_element(ans.begin(), ans.end());
  }
};
