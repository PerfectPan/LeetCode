/**
 * @param {string[]} words
 * @return {number}
 */
var countPrefixSuffixPairs = function(words) {
    const len = words.length;
    let ans = 0;
    for (let i = 0; i < len; ++i) {
        for (let j = i + 1; j < len; ++j) {
            if (words[j].startsWith(words[i]) && words[j].endsWith(words[i])) {
                ans++;
            }
        }
    }
    return ans;
};
