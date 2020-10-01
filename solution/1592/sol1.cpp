class Solution {
public:
  string reorderSpaces(string text) {
    vector<string> res;
    string tmp = "";
    int cnt = 0;
    for (int i = 0; i < text.length(); ++i) {
      if (text[i] >= 'a' && text[i] <= 'z') {
        tmp += text[i];
      } else {
        cnt += 1;
        if (tmp != "") {
          res.emplace_back(tmp);
          tmp = "";
        }
      }
    }
    if (tmp != "") {
      res.emplace_back(tmp);
    }
    int avg = cnt / max(1, (int)res.size() - 1);
    string ans = "";
    for (auto &s : res) {
      ans += s;
      for (int j = 0; j < avg && cnt > 0; ++j, --cnt) {
        ans += " ";
      }
    }
    for (; cnt > 0; --cnt) {
      ans += " ";
    }
    return ans;
  }
};