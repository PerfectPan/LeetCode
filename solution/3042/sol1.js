/**
 * @param {string[]} words
 * @return {number}
 */
var countPrefixSuffixPairs = function(words) {
    const n = words.length;
    let cnt = 0;
    for (let i = 0; i < n; ++i) {
        for (let j = i + 1; j < n; ++j) {
            if (words[j].startsWith(words[i]) && words[j].endsWith(words[i])) {
                cnt++;
            }
        }
    }
    return cnt;
};
