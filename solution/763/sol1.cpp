class Solution {
public:
  pair<int, int> seg[26];
  vector<int> partitionLabels(string S) {
    memset(seg, -1, sizeof(seg));
    for (int i = 0; i < S.size(); ++i) {
      int idx = S[i] - 'a';
      if (seg[idx].first == -1) {
        seg[idx].first = seg[idx].second = i;
      } else {
        seg[idx].second = i;
      }
    }
    sort(seg, seg + 26);
    int l, r, i = 0;
    vector<int> ans;
    while (i < 26 && seg[i].first == -1) {
      i++;
    }
    l = seg[i].first, r = seg[i].second;
    for (; i < 26; ++i) {
      if (seg[i].first != -1) {
        if (seg[i].first > r) {
          ans.push_back(r - l + 1);
          l = seg[i].first, r = seg[i].second;
        } else {
          r = max(r, seg[i].second);
        }
      }
    }
    ans.push_back(r - l + 1);
    return ans;
  }
};
