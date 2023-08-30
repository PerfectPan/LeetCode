// BFS 即可，模版题，之前有个什么倒水的也是类似的，三个瓶子水互倒，问最少几步能凑出 x 毫升的水
class Solution {
public:
    struct Node {
        int pos, type, step;
    };
    int vis[2][10010], stone[10010];
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        memset(vis, 0, sizeof(vis));
        queue<Node> Q;
        for (int obstable: forbidden) {
            stone[obstable] = 1;
        }

        Q.push(Node{0, 0, 0});
        vis[0][0] = 1;
        while (!Q.empty()) {
            auto node = Q.front();
            int pos = node.pos, type = node.type, step = node.step;
            Q.pop();
            if (pos == x) {
                return step;
            }
            if (type != 0) {
                int nxt = pos - b;
                if (!(nxt < 0 || vis[0][nxt] || stone[nxt])) {
                    vis[0][nxt] = 1;
                    Q.push(Node{nxt, 0, step + 1});
                }
            }

            int nxt = pos + a;
            if (nxt > 10000 || vis[1][nxt] || stone[nxt]) {
                continue;
            }
            vis[1][nxt] = 1;
            Q.push(Node{nxt, 1, step + 1});
        }
        return -1;
    }
};
