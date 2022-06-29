class Solution {
public:
    struct Node {
        int day,p;
        bool operator < (const Node& res) const {
            return res.day < day;
        }
    };
    int minimumLines(vector<vector<int>>& stockPrices) {
        vector<Node> res;
        for (auto& stock: stockPrices) {
            res.emplace_back((Node){stock[0], stock[1]});
        }
        sort(res.begin(), res.end());
        bool flag = false;
        int px, py, ans = 0;
        for (int i = 1; i < res.size(); ++i) {
            int x = res[i].day - res[i - 1].day;
            int y = res[i].p - res[i - 1].p;
            if (x != 0 && y != 0) {
                int g = __gcd(x, y);
                x /= g, y /= g;
            } else {
                if (x == 0) {
                    y = y > 0 ? 1 : -1;
                } else {
                    x = x > 0 ? 1 : -1;
                }
            }
            if (!flag) {
                flag = true;
                ans = 1;
            } else {
                if (!(px == x && py == y)) {
                    ans += 1;
                }
            }
            px = x, py = y;
        }
        return ans;
    }
};

