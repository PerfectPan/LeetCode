class Solution {
public:
  bool isPalindrome(int l, int r, string &s) {
    for (int i = l, j = r; i < j; ++i, --j) {
      if (s[i] != s[j]) {
        return false;
      }
    }
    return true;
  }
  bool check(string &a, string &b) {
    int n = a.length();
    for (int i = 0, j = n - 1; i <= j; ++i, --j) {
      if (a[i] != b[j]) {
        return isPalindrome(i, j, a) || isPalindrome(i, j, b);
      }
    }
    return true;
  }
  bool checkPalindromeFormation(string a, string b) {
    return check(a, b) || check(b, a);
  }
};
