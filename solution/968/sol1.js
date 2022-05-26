var minCameraCover = function(root) {
    const dfs = (root) => {
        if (!root) {
            return [Math.floor(Number.MAX_SAFE_INTEGER / 2), 0, 0];
        }
        let [la, lb, lc] = dfs(root.left);
        let [ra, rb, rc] = dfs(root.right);
        const a = lc + rc + 1;
        const b = Math.min(a, Math.min(la + rb, ra + lb));
        const c = Math.min(a, lb + rb);
        return [a, b, c];
    }

    return dfs(root)[1];
};

