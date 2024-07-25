class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size();
        int pre_0 = -1;
        int pre_2 = -1;
        int pre_7 = -1;
        int pre_5 = -1;
        int ans = 1e9;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (num[i] == '0') {
                cnt++;
                if (pre_0 != -1) {
                    ans = min(ans, i - pre_0 - 1 + (n - i - 1));
                }

                if (pre_5 != -1) {
                    ans = min(ans, i - pre_5 - 1 + (n - i - 1));
                }
                pre_0 = i;
            } else if (num[i] == '5') {
                if (pre_2 != -1) {
                    ans = min(ans, i - pre_2 - 1 + (n - i - 1));
                }
                if (pre_7 != -1) {
                    ans = min(ans, i - pre_7 - 1 + (n - i - 1));
                }

                pre_5 = i;
            } else if (num[i] == '2') {
                pre_2 = i;
            } else if (num[i] == '7') {
                pre_7 = i;
            }
        }

        return ans == 1e9 ? n - cnt : min(ans, n - cnt) ;
    }
};
