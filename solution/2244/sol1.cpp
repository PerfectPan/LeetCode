int f[100010];

bool inited = false;

void init() {
    if (inited) {
        return;
    }
    memset(f, -1, sizeof(f));
    inited = true;
    f[0] = 0; f[1] = -1; f[2] = f[3] = 1;
    for (int i = 4; i <= 100000; ++i) {
        if (f[i - 3] != -1) {
            f[i] = f[i - 3] + 1;
        }
        if (f[i - 2] != -1) {
            if (f[i] == -1) {
                f[i] = f[i - 2] + 1;
            } else {
                f[i] = min(f[i], f[i - 3] + 1);
            }
        }
    }
}

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        init();
        sort(tasks.begin(), tasks.end());
        int n = tasks.size();
        int l = 0;
        int ans = 0;
        while (l < n) {
            int r = l;
            for (; r < n && tasks[r] == tasks[l]; ++r);
            int cnt = r - l;
            if (f[cnt] == -1) {
                return -1;
            }
            ans += f[cnt];
            l = r;
        }
        return ans;
    }
};
