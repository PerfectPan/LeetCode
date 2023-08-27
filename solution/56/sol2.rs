impl Solution {
  pub fn merge(intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let mut intervals = intervals;
    intervals.sort_unstable();
    let mut ans = Vec::new();
    let mut i = 0;
    let n = intervals.len();

    while i < n {
      let (l, mut r) = (intervals[i][0], intervals[i][1]);

      while i + 1 < n && intervals[i + 1][0] <= r {
        r = r.max(intervals[i + 1][1]);
        i += 1;
      }

      ans.push(vec![l, r]);
      i += 1;
    }

    return ans;
  }
}
