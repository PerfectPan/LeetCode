/**
 * @param {number[][]} grid
 * @return {number}
 */
var surfaceArea = function(grid) {
    const dr = [0, 1, 0, -1];
    const dc = [1, 0, -1, 0];

    const N = grid.length;
    let ans = 0;

    for (let r = 0; r < N; ++r) {
        for (let c = 0; c < N; ++c) {
            if (grid[r][c] > 0) {
                ans += 2;
                for (let k = 0; k < 4; ++k) {
                    const nr = r + dr[k];
                    const nc = c + dc[k];
                    let nv = 0;
                    if (0 <= nr && nr < N && 0 <= nc && nc < N) {
                        nv = grid[nr][nc];
                    }

                    ans += Math.max(grid[r][c] - nv, 0);
                }
            }
        }
    }
    
    return ans;
};

