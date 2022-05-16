const dfs = (root, val) => {
    if (!root || val > root.val) {
        const cur = new TreeNode(val);
        cur.left = root;
        return cur;
    }
    root.right = dfs(root.right, val);
    return root;
}
var insertIntoMaxTree = function(root, val) {
    return dfs(root, val);
};

