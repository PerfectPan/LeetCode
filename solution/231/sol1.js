const __builtin_popcount = (n) => n ? (n & 1) + __builtin_popcount(n >> 1) : 0;
var isPowerOfTwo = function(n) {
    return n > 0 ? __builtin_popcount(n) === 1: false;
};