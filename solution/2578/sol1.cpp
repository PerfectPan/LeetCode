class Solution {
public:
    struct Node {
        int n, cnt;
        bool operator < (const Node& rhs) {
            return n < rhs.n;
        }
    };
    int splitNum(int num) {
        int nums[10] = {0};
        while (num > 0) {
            int x = num % 10;
            nums[x]++;
            num /= 10;
        }
        vector<Node> res;
        for (int i = 0; i < 10; ++i) {
            if (nums[i] > 0) {
                res.push_back((Node){i, nums[i]});
            }
        }
        sort(res.begin(), res.end());
        int A = 0, B = 0;
        for (int i = 0, j = 0; i < res.size(); ++i) {
            int cnt = res[i].cnt;
            int number = res[i].n;
            while (cnt > 0) {
                if (j & 1) {
                    B = B * 10 + number;
                } else {
                    A = A * 10 + number;
                }
                cnt--;
                j++;
            }
        }
        return A + B;
    }
};
