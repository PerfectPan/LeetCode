impl Solution {
    pub fn find_poisoned_duration(time_series: Vec<i32>, duration: i32) -> i32 {
        let mut r = -1;
        let mut ans = 0;
        for time in time_series {
            ans += time + duration - r.max(time);
            r = time + duration;
        }

        ans
    }
}
