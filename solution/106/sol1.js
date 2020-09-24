var buildTree = function (inorder, postorder) {
  let post_idx;
  const idx_map = new Map();
  const helper = (in_left, in_right) => {
    if (in_left > in_right) {
      return null;
    }

    const root_val = postorder[post_idx];
    const root = new TreeNode(root_val);

    const index = idx_map.get(root_val);

    post_idx--;
    root.right = helper(index + 1, in_right);
    root.left = helper(in_left, index - 1);
    return root;
  }

  post_idx = postorder.length - 1;

  let idx = 0;
  inorder.forEach((val, idx) => {
    idx_map.set(val, idx);
  });
  return helper(0, inorder.length - 1);
};