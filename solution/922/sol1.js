var sortArrayByParityII = function(nums) {
    let i = 0, j = 1;
    while (i < nums.length) {
        if (nums[i] % 2 === 0) {
            i += 2; // 寻找偶数下标中最左边的奇数
        } else if (nums[j] % 2 === 1) {
            j += 2; // 寻找奇数下标中最左边的偶数
        } else {
            [nums[i], nums[j]] = [nums[j], nums[i]];
            i += 2;
            j += 2;
        }
    }
    return nums;
};
