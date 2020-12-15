class Solution {
public:
  bool isIsomorphic(string s, string t) {
    unordered_map<char, int> trans;
    unordered_map<char, bool> vis;
    for (int i = 0; i < s.length(); ++i) {
      int idxa = s[i] - 'a', idxb = t[i] - 'a';
      if (trans.find(idxa) != trans.end() && trans[idxa] != idxb) {
        return false;
      }
      if (trans.find(idxa) == trans.end() && vis[idxb]) {
        return false;
      }
      trans[idxa] = idxb;
      vis[idxb] = true;
    }
    return true;
  }
};
