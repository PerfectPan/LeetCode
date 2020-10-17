const isPalindrome = (l, r, s) => {
  for (let i = l, j = r; i < j; ++i, --j) {
    if (s[i] !== s[j]) {
      return false;
    }
  }
  return true;
}
const check = (a, b) => {
  const n = a.length;
  for (let i = 0, j = n - 1; i <= j; ++i, --j) {
    if (a[i] !== b[j]) {
      return isPalindrome(i, j, a) || isPalindrome(i, j, b);
    }
  }
  return true;
}
var checkPalindromeFormation = function (a, b) {
  return check(a, b) || check(b, a);
};
