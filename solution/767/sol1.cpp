class Solution {
public:
  string reorganizeString(string S) {
    string ans = "";
    int n = S.length();
    vector<pair<int, int>> cnt;
    for (int i = 0; i < 26; ++i) {
      cnt.push_back(make_pair(0, i));
    }
    for (int i = 0; i < n; ++i) {
      int idx = S[i] - 'a';
      if (++cnt[idx].first > (n + 1) / 2) {
        return ans;
      }
    }
    sort(cnt.begin(), cnt.end());
    reverse(cnt.begin(), cnt.end());
    for (int i = 0; i < n; ++i) {
      ans += "0";
    }
    for (int i = 0, j = 0; i < cnt.size(); ++i)
      if (cnt[i].first > 0) {
        for (int k = 0; k < cnt[i].first; ++k) {
          ans[j] = cnt[i].second + 'a';
          j += 2;
          if (j >= n) {
            j = 1;
          }
        }
      }
    return ans;
  }
};
