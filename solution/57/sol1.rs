impl Solution {
    pub fn insert(intervals: Vec<Vec<i32>>, new_interval: Vec<i32>) -> Vec<Vec<i32>> {
        let mut ans: Vec<Vec<i32>> = Vec::new();
        let mut consumed = false;
        for interval in intervals.iter() {
            let len = ans.len();

            if consumed {
                if interval[0] <= ans[len - 1][1] {
                    ans[len - 1][1] = ans[len - 1][1].max(interval[1]);
                } else {
                    ans.push(vec![interval[0], interval[1]]);
                }
            } else {
                let l = interval[0];
                let r = interval[1];
                let nl = new_interval[0];
                let nr = new_interval[1];

                if nl > r {
                    ans.push(vec![l, r]);
                } else if nr < l {
                    consumed = true;
                    ans.push(vec![nl, nr]);
                    ans.push(vec![l, r]);
                } else {
                    let ml = l.min(nl);
                    let mr = r.max(nr);
                    consumed = true;
                    ans.push(vec![ml, mr]);
                }
            }
        }
        if !consumed {
            ans.push(new_interval);
        }

        ans
    }
}
