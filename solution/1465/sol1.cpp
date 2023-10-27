// 横切竖切单独考虑即可，每个方向贪心找间隔最大的
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int prev = 0, h_mx = 0, v_mx = 0;
        for (int cut: horizontalCuts) {
            h_mx = max(h_mx, cut - prev);
            prev = cut;
        }
        prev = 0;
        for (int cut: verticalCuts) {
            v_mx = max(v_mx, cut - prev);
            prev = cut;
        }
        return 1LL * v_mx * h_mx % 1000000007;
    }
};
