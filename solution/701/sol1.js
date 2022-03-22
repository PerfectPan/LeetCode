/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} val
 * @return {TreeNode}
 */
var insertIntoBST = function(root, val) {
    if (root === null) {
        return new TreeNode(val);
    }
    let pos = root;
    while (pos !== null) {
        if (val < pos.val) {
            if (pos.left !== null) {
                pos = pos.left;
            } else {
                pos.left = new TreeNode(val);
                break;
            }
        } else {
            if (pos.right !== null) {
                pos = pos.right;
            } else {
                pos.right = new TreeNode(val);
                break;
            }
        }
    }
    return root;
};

