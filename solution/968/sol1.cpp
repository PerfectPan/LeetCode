class Solution {
public:
    tuple<int, int, int> dfs(TreeNode* root) {
        if (root == nullptr) {
            return tuple<int, int, int>(INT_MAX / 2, 0, 0);
        }
        auto [la, lb, lc] = dfs(root->left);
        auto [ra, rb, rc] = dfs(root->right);
        int a = lc + rc + 1;
        int b = min(a, min(la + rb, ra + lb));
        int c = min(a, lb + rb);
        return tuple<int, int, int>(a, b, c);
    }

    int minCameraCover(TreeNode* root) {
        auto [a, b, c] = dfs(root);
        return b;
    }
};

