var reorderSpaces = function (text) {
  const n = text.length;
  let totalWords = 0;
  let totalSpaces = 0;
  let i = 0;
  while (i < n) {
    while (i < n && text.charAt(i) === ' ') {
      i++;
      totalSpaces++;
    }
    if (i < n) {
      totalWords++;
      while (i < n && text.charAt(i) !== ' ') {
        i++;
      }
    }
  }
  let div = 0, mod = 0;
  if (totalWords > 1) {
    div = Math.floor(totalSpaces / (totalWords - 1));
    mod = totalSpaces % (totalWords - 1);
  } else {
    mod = totalSpaces;
  }

  let ret = "";
  i = 0;
  let nWords = 0;
  while (nWords < totalWords) {
    while (i < n && text.charAt(i) === ' ') {
      i++;
    }
    nWords++;
    while (i < n && text.charAt(i) !== ' ') {
      ret += text.charAt(i);
      i++;
    }
    const nSpaces = (nWords === totalWords) ? mod : div;
    ret += new Array(nSpaces).fill(' ').join('');
  }
  return ret;
};