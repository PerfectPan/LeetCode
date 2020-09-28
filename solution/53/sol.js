var maxSubArray = function (nums) {
  let dp = 0, ans = Number.NEGATIVE_INFINITY;
  for (const x of nums) {
    dp = Math.max(x, dp + x);
    ans = Math.max(ans, dp);
  }
  return ans;
};
