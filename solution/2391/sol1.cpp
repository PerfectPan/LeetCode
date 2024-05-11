class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int res = 0;
        int cnt_m = 0, cnt_p = 0, cnt_g = 0;
        for (int i = 0; i < garbage.size(); ++i) {
            if (i > 0) {
                cnt_m += travel[i - 1];
                cnt_p += travel[i - 1];
                cnt_g += travel[i - 1];
            }


            int is_m = 0, is_p = 0, is_g = 0;
            for (int j = 0; j < garbage[i].size(); ++j) {
                is_m += garbage[i][j] == 'M';
                is_p += garbage[i][j] == 'P';
                is_g += garbage[i][j] == 'G';
            }
            if (is_m > 0) {
                res += cnt_m + is_m;
                cnt_m = 0;
            }
            if (is_p > 0) {
                res += cnt_p + is_p;
                cnt_p = 0;
            }
            if (is_g > 0) {
                res += cnt_g + is_g;
                cnt_g = 0;
            }
        }
        return res;
    }
};
