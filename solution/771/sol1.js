// var numJewelsInStones = function (J, S) {
// 	const jewelsSet = new Set(J.split(""));
// 	return S.split("").reduce((prev, val) => {
// 		return prev + jewelsSet.has(val);
// 	}, 0);
// };

// class PriceSystem {
//     constructor() {
//         this.info_list = [];
//         this.weight_dict = {};
//     }

//     /** 
//      * @param {number} date 
//      * @param {number} price
//      * @return {number}
//      */
//     add(date, weight) {
//         if (this.weight_dict[date] !== undefined) {
//             return -1;
//         }
//         while (this.info_list.length > 0 && this.info_list[this.info_list.length - 1][1] < weight) {
//             this.info_list.pop();
//         }
//         this.info_list.push([date, weight]);
//         this.weight_dict[date] = weight;
//         return weight;
//     }

//     /** 
//      * @param {number} date 
//      * @return {number}
//      */
//     query(date) {
//         if (this.weight_dict[date] === undefined) {
//             return -1;
//         }
//         const weight = this.weight_dict[date];
//         let l = 0, r = this.info_list.length - 1;
//         while (l < r) {
//             const mid = Math.floor((l + r) / 2);
//             if (this.info_list[mid][1] <= weight) {
//                 r = mid - 1;
//             } else {
//                 l = mid;
//             }
//         }
//         if (l==r && this.info_list[l][0] > date && this.info_list[l][1] > weight) {
//             return this.info_list[l][0];
//         }
//        return -1

//     }

//     rebuild_info_list() {
//         this.info_list = [];
//         const data = Object.entries(this.weight_dict);
//         data.sort()
//         for (const [date, weight] of data) {
//             while (this.info_list.length > 0 && this.info_list[this.info_list.length - 1][1] < weight) {
//                 this.info_list.pop();
//             }
//             this.info_list.push([date, weight]);
//         } 
//     }

//     /** 
//      * @param {number} date 
//      * @return {number}
//      */
//     delete(date) {
//         if (this.weight_dict[date] === undefined) {
//             return -1;
//         }
//         delete this.weight_dict[date];
//         this.rebuild_info_list();
//         return 1;
//     }
// }

// class Solution {
// public:
//     int len, ans, digit[10];
//     bool dfs(int pos, int cur, int res, bool flag) {
//         if (pos == 0) {
//             ans = res;
//             return true;
//         }
//         int limit = flag ? digit[pos] : 9;
//         for (int i = cur + 1; i <= limit; ++i) {
//             if (dfs(pos - 1, i, res * 10 + i, res, i == limit)) {
//                 return true;
//             }
//         }
//         return false;
//     }
//     int monotoneIncreasingDigits(int N) {
//         if (!N) {
//             return 0;
//         }
//         len = 0;
//         while (N) {
//             digit[len++] = N % 10;
//             N /= 10;
//         }
//         if (!dfs(len, 0, 0, 0)) {
//             int cur = 9;
//             for (int i = 0; i < len - 1; ++i) {
//                 ans = ans * 10 + cur;
//                 cur -= 1;
//             }
//         }
//         return ans;
//     }
// };

// // 记录无向图
// let edges = [];
// // 记录搜索过程中每个数是否被使用过
// let used = [];
// // 记录搜索过程中的序列
// const ans = [];
// // 是否找到答案
// let found = false;

// const dfs = (pos, n) => {
//     if (pos == n) {
//         // 搜索完成，还需要判断首尾之和是否为完全平方数
//         const sum = ans[0] + ans[ans.length - 1];
//         const root = Math.floor(Math.sqrt(sum));
//         if (root * root === sum) {
//             found = true;
//         }
//     }
//     else if (pos === 0) {
//         // 由于酥饼是圆形，因此可以指定第一个数选择 1
//         used[1] = true;
//         ans.push(1);
//         dfs(pos + 1, n);
//         if (found) {
//             return;
//         }
//         used[1] = false;
//         ans.pop();
//     }
//     else {
//         // 只能选与上一个数形成完全平方数，并且还未被选择的数
//         for (const num of edges[ans[ans.length - 1]]) {
//             if (!used[num]) {
//                 used[num] = true;
//                 ans.push(num);
//                 dfs(pos + 1, n);
//                 if (found) {
//                     return;
//                 }
//                 used[num] = false;
//                 ans.pop();
//             }
//         }
//     }
// }

// const minimalFruitPie = () => {
//     // 从小到大枚举 n
//     for (let n = 2; ; ++n) {
//         edges = new Array(n + 1).fill(0).map(v => []);
//         // 建立无向图
//         for (let i = 1; i <= n; ++i) {
//             // 枚举平方数 root^2
//             for (let root = 1; root * root <= i + n; ++root) {
//                 const j = root * root - i;
//                 if (j > 0 && j > i) {
//                     edges[i].push(j);
//                     edges[j].push(i);
//                 }
//             }
//         }
//         used = new Array(n + 1).fill(0);
//         dfs(0, n);
//         if (found) {
//             return ans;
//         }
//     }
// }

// const effectiveParkingArea = () => {
//     const init = new Status(0, M * N - 1, 0);
//     const seen = new Map();
//     const queue = [];

//     seen.set(init.hashCode(), init);
//     queue.push(init);

//     while (queue.length) {
//         const cur = queue.shift();
//         const neighbors = cur.getAdjacent();
//         for (const neighbor of neighbors) {
//             if (neighbor.finished()) {
//                 return neighbor.step;
//             }
//             if (!seen.has(neighbor.hashCode())) {
//                 seen.set(neighbor.hashCode(), neighbor);
//                 queue.push(neighbor);
//             }
//         }
//     }
//     // 不可能的情况
//     return -1;
// }

// // 停车场大小
// const M = 10;
// const N = 10;

// class Status {
//     constructor(car, space, step) {
//         // 目标车所在的格子
//         this.car = car;
//         // 空位所在的格子
//         this.space = space;
//         // 移动的步数
//         this.step = step;
//     }

//     hashCode() {
//         return this.car * M * N + this.space;
//     }

//     // 空位左移
//     goLeft() {
//         // 在最左列
//         if (this.space % N === 0) {
//             return null;
//         }
//         return this.car === this.space - 1 ? new Status(this.space, this.car, this.step + 1) : new Status(this.car, this.space - 1, this.step + 1);
//     }

//     // 空位右移
//     goRight() {
//         // 在最右列
//         if (this.space % N === N - 1) {
//             return null;
//         }
//         return this.car === this.space + 1 ? new Status(this.space, this.car, this.step + 1) : new Status(this.car, this.space + 1, this.step + 1);
//     }

//     // 空位上移
//     goUp() {
//         // 在最上行
//         if (Math.floor(this.space / N) === 0) {
//             return null;
//         }
//         return this.car === this.space - N ? new Status(this.space, this.car, this.step + 1) : new Status(this.car, this.space - N, this.step + 1);
//     }

//     // 空位下移
//     goDown() {
//         // 在最下行
//         if (Math.floor(this.space / N) === M - 1) {
//             return null;
//         }
//         return this.car === this.space + N ? new Status(this.space, this.car, this.step + 1) : new Status(this.car, this.space + N, this.step + 1);
//     }

//     // 辅助函数，返回空位与四个方向的交换结果，方便编码
//     getAdjacent() {
//         const adjacent = [this.goLeft(), this.goRight(), this.goUp(), this.goDown()];
//         const neighbors = [];
//         for (const neighbor of adjacent) {
//             if (neighbor !== null) {
//                 neighbors.push(neighbor);
//             }
//         }
//         return neighbors;
//     }

//     // 判断车是否到达右下角
//     finished() {
//         return this.car === M * N - 1;
//     }
// }


var result = function(nums) {
    const n = nums.length;
    const pre = new Array(n).fill(-1);
    const suff = new Array(n).fill(-1);
    for (let i = 1; i < n; ++i) {
        pre[i] = i - 1;
    } 
    for (let i = 0; i < n - 1; ++i) {
        suff[i] = i + 1;
    }
    const ans = [];
    for (let i = 1; i < n - 1; ++i) {
        if ()
    }
    return ans;
};  


// var specialTree = function(weights, cnt) {
//     const m = weights.length;
//     const n = weights[0].length;
//     const sum = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0));
//     let mx = -1, ans = 0;
//     for (let i = 0; i < m; ++i) {
//         for (let j = 0; j < n; ++j) {
//             sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + weights[i][j];
//             if (i + 1 >= cnt && j + 1 >= cnt) {
//                 const S = sum[i + 1][j + 1] + sum[i + 1 - cnt][j + 1 - cnt] - sum[i + 1 - cnt][j + 1] - sum[i + 1][j + 1 - cnt];
//                 if (S > mx) {
//                     mx = S;
//                     ans = 1;
//                 }
//             }
//         }
//     }
//     const vis = new Array(m + 2).fill(0).map(() => new Array(n + 2).fill(0));
//     const S = new Set();
//     for (let i = cnt; i <= m; ++i) {
//         for (let j = cnt; j <= n; ++j) {
//             const S = sum[i][j] - sum[i - cnt][j] - sum[i][j - cnt] + sum[i - cnt][j - cnt];
//             if (S === mx) {
//                 vis[i + 1][j + 1] += 1;
//                 vis[i - cnt + 1][j + 1] -= 1;
//                 vis[i + 1][j - cnt + 1] -= 1;
//                 vis[i - cnt + 1][j - cnt + 1] += 1;
                
//             }
//         }
//     }
//     for (let i = 1; i <= m; ++i) {
//         for (let j = 1; j <= n; ++j) {
//             vis[i][j] += vis[i - 1][j] + vis[i][j - 1] - vis[i - 1][j - 1];
//             if (vis[i][j]) {
//                 S.add(weights[i - 1][j - 1]);
//             }
//         }
//     }
//     return S.size;
// };


// var number = function(area, base, count, constA, constB, constC) {
//     const data = [base];
//     for (let i = 1; i < count; ++i) {
//         data.push((data[i - 1] * constA + constB) % constC + 1 + data[i]);
//     }
//     let ans = 0;
//     for (let l = 0, r = count - 1; l < count; ++l) {
//         while (r >= 0 && area < data[l] * data[r]) {
//             r -= 1;
//         }
//         ans += r + 1;
//     }
//     return ans;
// };

// var squareShopping = function(grid, price) {
//     const n = grid.length;
//     const pre = new Array(n + 1).fill(0).map(() => new Array(n + 1).fill(0));
//     for (let i = 0; i < n; ++i) {
//         for (let j = 0; j < n; ++j) {
//             pre[i + 1][j + 1] = pre[i][j + 1] + pre[i + 1][j] - pre[i][j] + grid[i][j];
//         }
//     }
//     let l = 1, r = n, ans = 0;
//     while (l <= r) {
//         const mid = Math.floor((l + r) / 2.0);
//         let flag = true;
//         for (let i = mid; i <= n; ++i) {
//             for (let j = mid; j <= n; ++j) {
//                 const S = pre[i][j] - pre[i][j - mid] - pre[i - mid][j] + pre[i - mid][j - mid];
//                 if (S > price) {
//                     flag = false;
//                     i = n + 1;
//                     j = n + 1;
//                 }
//             }
//         }
//         if (flag) {
//             ans = mid;
//             l = mid + 1;
//         } else {
//             r = mid - 1;
//         }
//     }
//     return ans;
// };

// class Solution {
// public:
//     int getSum(int r1, int c1, int r2, int c2, vector< vector<int> >&presum) {
//         return presum[r2][c2] - presum[r1 - 1][c2] - presum[r2][c1 - 1] + presum[r1 - 1][c1 - 1];
//     }
//     int squareShopping(vector<vector<int>>& grid, int price) {
//         int n = grid.size();
//         vector< vector<int> > presum(n + 1, vector<int>(n + 1, 0));
//         for(int i = 1; i <= n; ++i)
//             for(int j = 1; j <= n; ++j)
//                 presum[i][j] = presum[i - 1][j] + presum[i][j - 1] - presum[i - 1][j - 1] + grid[i - 1][j - 1];
//         int ans = n;
//         for(int i = 1; i <= n - ans + 1; ++i)
//             for(int j = 1; j <= n - ans + 1; ++j)
//                 while(ans > 0 && getSum(i, j, i + ans - 1, j + ans - 1, presum) > price) --ans;
//         return ans;
//     }
// };
    
    