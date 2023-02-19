class Solution {
public:
    struct PassRatio {
        int pass, total;
        bool operator < (const PassRatio& rhs) const {
            return 1LL * (total - pass) * rhs.total * (rhs.total + 1) < 1LL * (rhs.total - rhs.pass) * total * (total + 1);
        }
    };
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double ans = 0;
        priority_queue<PassRatio> Q;
        for (int i = 0; i < classes.size(); ++i) {
            Q.push((PassRatio){classes[i][0], classes[i][1]});
        }
        for (int i = 1; i <= extraStudents; ++i) {
            PassRatio t = Q.top();
            Q.pop();
            Q.push((PassRatio){t.pass + 1, t.total + 1});
        }
        while (!Q.empty()) {
            PassRatio t = Q.top();
            Q.pop();
            ans += 1.0 * t.pass / t.total;
        }
        return 1.0 * ans / classes.size();
    }
};
