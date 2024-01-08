class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        auto cal = [&](int x, int y) -> int {
            int xDiff = points[x][0] - points[y][0];
            int yDiff = points[x][1] - points[y][1];
            return xDiff * xDiff + yDiff * yDiff;
        };

        for (int i = 0; i < n; ++i) {
            vector<int> vec;
            for (int j = 0; j < n; ++j) if (i != j) {
                vec.push_back(cal(i, j));
            }
            sort(vec.begin(), vec.end());
            int j = 0;
            while (j < n - 1) {
                int r = j;
                for ( ; r < n - 1 && vec[j] == vec[r]; ++r);
                ans += (r - j) * (r - j - 1);
                j = r; 
            }
        }
        return ans;
    }
};
