impl Solution {
  pub fn capture_forts(forts: Vec<i32>) -> i32 {
      let mut ans: i32 = 0;
      let mut pre: i32 = -1;

      for (index, fort) in forts.iter().enumerate() {
          if *fort == 1 || *fort == -1 {
              if pre >= 0 && *fort != forts[pre as usize] {
                  ans = ans.max((index as i32) - pre - 1);
              }
              pre = index as i32;
          }
      }

      ans
  }
}
