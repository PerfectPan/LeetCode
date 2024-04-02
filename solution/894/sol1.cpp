/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 偶数不存在真二叉树
// 一棵有 n 个节点的真二叉树恰好有 (n + 1) / 2 个叶子
// f[i] 表示有 i 个叶子的所有真二叉树列表
vector<TreeNode*> f[11];

auto init = [] {
    f[1] = { new TreeNode() };
    for (int i = 2; i < 11; ++i) {
        for (int j = 1; j < i; ++j) {
            for (auto left: f[j]) {
                for (auto right: f[i - j]) {
                    f[i].push_back(new TreeNode(0, left, right));
                }
            }
        }
    }
    return 0;
}();
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        return f[n % 2 ? (n + 1) / 2 : 0];
    }
};
