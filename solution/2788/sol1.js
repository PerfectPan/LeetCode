/**
 * @param {string[]} words
 * @param {character} separator
 * @return {string[]}
 */
var splitWordsBySeparator = function(words, separator) {
    return words.reduce((prev, word) => {
      prev.push(...word.split(separator).filter((v) => !!v));
      return prev;     
    }, []);
};
