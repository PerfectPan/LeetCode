class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int ans = 0;
        vector<int> t1(nums);

        for (int i = 1; i < t1.size(); ++i) {
            if (i & 1) {
                if (t1[i] >= t1[i - 1]) {
                    ans += t1[i] - t1[i - 1] + 1;
                    t1[i] = t1[i - 1] - 1;
                }
            } else {
                if (t1[i] <= t1[i - 1]) {
                    ans += t1[i - 1] - t1[i] + 1;
                    t1[i - 1] = t1[i] - 1;
                }
            }
        }

        int ans2 = 0;
        vector<int> t2(nums);

        for (int i = 1; i < t2.size(); ++i) {
            if (i & 1) {
                if (t2[i] <= t2[i - 1]) {
                    ans2 += t2[i - 1] - t2[i] + 1;
                    t2[i - 1] = t2[i] - 1;
                }
            } else {
                if (t2[i] >= t2[i - 1]) {
                    ans2 += t2[i] - t2[i - 1] + 1;
                    t2[i] = t2[i - 1] - 1;
                }
            }
        }

        return min(ans, ans2);
    }
};

