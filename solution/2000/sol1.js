var reversePrefix = function(word, ch) {
    const idx = word.split('').findIndex((v) => v === ch);
    if (~idx) {
        word = word.substring(0, idx + 1).split('').reverse().join('') + word.substring(idx + 1);
    }
    return word;
};

