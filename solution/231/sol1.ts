const __builtin_popcount = (n: number): number => n ? (n & 1) + __builtin_popcount(n >> 1) : 0;
function isPowerOfTwo(n: number): boolean {
    return n > 0 ? __builtin_popcount(n) === 1 : false;
};
